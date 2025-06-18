#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PALAVRA 50

//declarando as variaveis
    char comando[100], comando1[100], comando2[100], comando3[100], comando4[100], caminho[100], nome[50], letra, testes, ch;
    int i = 0, count = 0, result = 0, escolha = 0;
    FILE *fp;
    FILE *fj,*quest;

int procurarPalavra(const char *caminhoArquivo, const char *palavra) 
{
  FILE *arquivo = fopen(caminhoArquivo, "r");
  char linha[TAMANHO_PALAVRA];

  while (fgets(linha, sizeof(linha), arquivo) != NULL) 
  {
    if (strstr(linha, palavra) != NULL) 
    {
      fclose(arquivo);
      return 1;  // A palavra foi encontrada
    }
  }
  fclose(arquivo);
  return 0;  // A palavra não foi encontrada
}

void SubmeterProblema()
{
  const char *caminhoArquivo = "C:/Users/mb.sampaio/Documents/Jones/a.txt";
  const char *palavraProcurada = "nenhuma";
  const char *palavraProcurada2 = "error";

  //Lendo a letra do desafio
  printf("\nDigite a letra do desafio que deseja submeter\n");
  scanf(" %c", &letra);

  //Lendo o nome do arquivo a ser testado
  printf("\nDigite o nome do arquivo do seu codigo\n");
  scanf("%s", nome);
  printf("\n");

  //Criando executavel para o programa a ser testado
  sprintf(comando2, "gcc %s.c -o %s 2> a.txt", nome, nome);
  system(comando2);

  //Verificando se ocorreu algum erro de compilação
  int result = procurarPalavra(caminhoArquivo, palavraProcurada2);
  if(result == 1)
  {
    printf("Ocorreu um erro de compilacao!\n");
    return;
  }

  //Calculando quantos casos de teste temos
  sprintf(comando1, "dir %c\\input /A-D /B", letra);
  fp = popen(comando1, "r");
  while (1) 
  {
    ch = fgetc(fp);
    if (ch == EOF) 
    {
      break;
    }

    if (ch == '\n') 
    {
      count++;
    }
  }
  pclose(fp);

  //fazendo os testes e gerando os arquivos de resultados
  for(i = 1;i <= count; i++)
  {
    sprintf(comando, "%s < %c/input/%d.txt > %c/temp/%d.txt", nome, letra, i, letra, i);
    system(comando);
  }

  //Comparando os arquivos de resultado e de saida esperada
  for(i = 1;i <= count; i++)
  {
    sprintf(comando4, "fc /B %c\\output\\%d.txt %c\\temp\\%d.txt > C:/Users/mb.sampaio/Documents/Jones/a.txt", letra, i, letra, i);
    system(comando4);

    int result = procurarPalavra(caminhoArquivo, palavraProcurada);

    if (result == 1) 
    {
      if(i == count)
      {
        printf("O caso de teste %d esta correto!\n\n", i);
      }
      else
      {
        printf("O caso de teste %d esta correto!\n", i);
      }
    } 
    else
    {
      printf("O caso de teste %d esta incorreto!\n", i);
    }
  }

  system("del a.txt");
  return;
}

void MostrarProblema()
{
  printf("Digite a letra do desafio que deseja visualizar!\n");
  scanf(" %c", &letra);
  sprintf(caminho, "%c/quest.txt" , letra);
  quest = fopen(caminho, "r");
  while((letra = fgetc(quest)) != EOF)//lê infinitamente até o control + D
    {
    printf("%c",letra);
    }
  fflush(stdout);//limpa buffer

  fclose(quest);//fecha o arquivo
  return;
}

int main() 
{
  while(1)
  {
  printf("##############################\n####### Boca Simulator #######\n##############################\n\n");

  printf("1 - Submeter um problema\n2 - Mostrar descricao do problema\n3 - Sair\n\nDigite um numero e escolha o que voce quer fazer!\n");
  scanf("%d", &escolha);

  switch(escolha)
  {
    case 1 :
    SubmeterProblema();
    break;
    case 2 :
    MostrarProblema();
    break;
    case 3 :
    return 0;
    break;
  }
  }
  return 0;
}
