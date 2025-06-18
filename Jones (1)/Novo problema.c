#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

//não precisa repassar essa variavel:
  char comando[100];
  char letra;

//Para verificar se a pasta a ser criada já existe:

int pastaExiste() {
    struct stat st;
	sprintf(comando, "C:\\Users\\mb.sampaio\\Documents\\Jones\\%c", letra);
    if (stat(comando, &st) == 0) {
        // stat foi bem-sucedido, o caminho existe
        return S_ISDIR(st.st_mode) ? 1 : 0;  // Verifica se é um diretório
    } else {
        // stat falhou, o caminho não existe
        return 0;
    }
}

int main() 
{
  //Precisa declarar o entradas e o existe
  int entradas, i, existe;
  //Não precisa declarar essa
  char comando[100];
  while (1) 
  {
    printf("Digite a letra do problema a ser criado:\n");
    scanf(" %c", &letra);  
    existe = pastaExiste();
    if(existe == 1)
    {
      printf("Problema ja existente, por favor escolha outra letra\n");
    }
    else
    {
      break;
    }
  }
  sprintf(comando, "mkdir %c", letra);
  system(comando);
  
  sprintf(comando, "mkdir %c\\input", letra);
  system(comando);
  
  sprintf(comando, "mkdir %c\\output", letra);
  system(comando);
  
  sprintf(comando, "mkdir %c\\temp", letra);
  system(comando);
  
  sprintf(comando, "%c\\quest.txt", letra);
  FILE *descricao = fopen(comando, "w");
  printf("\nDigite a descricao do seu problema, termine a descricao com Ctrl + c:\n");
  while((letra = getchar()) != '§')
  {
    fputc(letra, descricao);
  }
  fflush(stdout);//limpa buffer

  fclose(descricao);//fecha o arquivo
  
  printf("Digite a quantidades de entradas e saidas\n:");
  scanf("%d", &entradas);  
  
  for(i = 1;i <= entradas;i++)
  {
    sprintf(comando, "%c\\input\\%d.txt", letra, i);
    FILE *entrada = fopen(comando, "w");
    printf("\nDigite a entradad numero %d do seu problema, termine a descrição da entrada com Ctrl + c:\n", i);
    while((letra = getchar()) != EOF)
    {
      fputc(letra, entrada);
    }
    fflush(stdout);//limpa buffer

    fclose(entrada);//fecha o arquivo

    sprintf(comando, "%c\\output\\%d.txt", letra, i);
    FILE *saida = fopen(comando, "w");
    printf("\nDigite a saida esperada numero %d do seu problema, termine a descrição com Ctrl + c:\n", i);
    while((letra = getchar()) != EOF)
    {
      fputc(letra, saida);
    }
    fflush(stdout);//limpa buffer

    fclose(saida);//fecha o arquivo
  }

  return 0;
}
