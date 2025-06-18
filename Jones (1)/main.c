#include <stdio.h>
#include <stdlib.h>

void lb()
{
  ((getchar() != '\n') && (!EOF));
}

struct dados
{
  char Nome[50];
  int Senha;
  char Inad;
};

int main() {
  struct dados Dados[100];
  int i = 0, j = 0, k = 0;
  while(i != 100)
  {
    scanf(" %[^\n]", Dados[i].Nome);
    
    if(Dados[i].Nome[0] == 'S' && Dados[i].Nome[1] == 'A' && Dados[i].Nome[2] == 'I' && Dados[i].Nome[3] == 'R')
    {
      break;
    }
    scanf("%d", &Dados[i].Senha);

    scanf(" %c", &Dados[i].Inad);
    i++;
  }
  while(scanf("%d", &k) != -1)
  {
    for(i = 0; i < 100; i++)
    {
      if(k == Dados[i].Senha)
      {
        if(Dados[i].Inad == 'P')
        {
        printf("%s, seja bem-vindo(a)!\n", Dados[i].Nome);
        break;
        }
        if(Dados[i].Inad == 'F')
        {
        printf("Não está esquecendo de algo, %s? Procure a recepção!\n", Dados[i].Nome);
        break;
        }
      }
      else if(i == 99)
      {
        printf("Seja bem-vindo(a)! Procure a recepção!\n");
        break;
      }
    }
  }
  return 0;
}
