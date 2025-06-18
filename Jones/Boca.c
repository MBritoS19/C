#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define TAMANHO_PALAVRA 50

	//declarando as variaveis
	char comando[100], comando1[100], comando2[100], comando3[100], comando4[100], caminho[100], nome[50], letra, testes, ch, linha[TAMANHO_PALAVRA];
    int i = 0, count = 0, result = 0, escolha = 0, existe, entradas;
    struct stat st;
    const char *caminhoArquivo = "C:/Users/mb.sampaio/Documents/Jones/a.txt", *palavraProcurada = "nenhuma", *palavraProcurada2 = "error";
    FILE *fp, *fj, *quest, *arquivo, *entrada, *saida;

//Cria as pastas e os arquivos para que seja adicionado um novo problema
void CriarProblema() 
{
  	//Entrada do caracter do problema a ser criado
  	while (1) 
  	{
  		//solicita o caracter que vai nomear o problema a ser criado
    	printf("\nDigite a letra do problema a ser criado:\n");
    	scanf(" %c", &letra);
    	
    	//Verifica se o problema solicitado já foi criado
    	existe = pastaExiste();
    	if(existe == 1)
    	{
      		printf("\nProblema ja existente, por favor escolha outra letra\n");
    	}
    	else
    	{
      		break;  //Como o problema não existe o while é parado
    	}
  	}
  	//Cria a pasta primaria do problema
  	sprintf(comando, "mkdir %c", letra);
  	system(comando);
  	
  	//Cria a pasta das entradas a serem inseridas
  	sprintf(comando, "mkdir %c\\input", letra);
  	system(comando);
  	
  	//Cria a pasta das saidas esperadas
  	sprintf(comando, "mkdir %c\\output", letra);
  	system(comando);
  	
  	//Cria a pasta da saida
  	sprintf(comando, "mkdir %c\\temp", letra);
  	system(comando);
  	
  	//Cria o arquivo que descreve o desafio do problema em questão
  	sprintf(comando, "%c\\quest.txt", letra);
  	FILE *descricao = fopen(comando, "w");
  	printf("\nArquivo para adicao da descricao do problema criado, se encontra em: C:/Users/mb.sampaio/Documents/Jones/%c/quest.txt\n\n", letra);
  	fclose(descricao);//fecha o arquivo
  	
  	//Solicita a quantidade de entradas e saidas que o problema vai ter
  	printf("Digite a quantidades de entradas e saidas esperadas:\n");
  	scanf("%d", &entradas);  
  	
  	//Cria os arquivos de entrada e saida do problema
  	for(i = 1;i <= entradas;i++)
  	{
  		//Começando a criar as entradas para os problemas
    	sprintf(comando, "%c\\input\\%d.txt", letra, i);
    	entrada = fopen(comando, "w");
    	printf("\nArquivo para adicao da entrada de numero %d do problema criado, o arquivo a ser editado se encontra em: C:/Users/mb.sampaio/Documents/Jones/%c/input/%d.txt\n", i, letra, i);
    	fclose(entrada);//fecha o arquivo
		
		//Começa a criar os arquivos para adicionar as saidas esperadas
    	sprintf(comando, "%c\\output\\%d.txt", letra, i);
    	saida = fopen(comando, "w");
    	printf("\nArquivo para adicao da saida esperada de numero %d do problema criado, o arquivo a ser editado se encontra em: C:/Users/mb.sampaio/Documents/Jones/%c/input/%d.txt\n", i, letra, i);
    	fclose(saida);//fecha o arquivo
  	}
  	printf("\n");
  	return;
}

//Verificar se uma pasta existe
int pastaExiste() 
{
	//criando o caminho a ser testado
	sprintf(comando, "C:\\Users\\mb.sampaio\\Documents\\Jones\\%c", letra);
    if (stat(comando, &st) == 0) 
	{
        // stat foi bem-sucedido, o caminho existe
        return S_ISDIR(st.st_mode) ? 1 : 0;  // Verifica se é um diretório
    } 
	else 
	{
        // stat falhou, o caminho não existe
        return 0;
    }
}

//Procura uma palavra especifica em um arquivo
int procurarPalavra(const char *caminhoArquivo, const char *palavra) 
{
	//abrindo o arquivo onde a palavra pode estar
	arquivo = fopen(caminhoArquivo, "r");
	
	//Buscando linha a linha pela palavra
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

//Submeter uma execução a um problema do boca
void SubmeterProblema()
{
	//Lendo a letra do desafio
	while (1) 
	{
		//Solicitando a letra do desafio a ser executado
  		printf("\nDigite a letra do desafio que deseja submeter\n");
  		scanf(" %c", &letra);
  		
  		//Verificando se esse desafio existe
  		existe = pastaExiste();
    	if(existe == 0)
    	{
      		printf("\nProblema nao existente, por favor escolha corretamente\n");
    	}
    	else
    	{
      		break;
    	}
	}	

	//Lendo o nome do arquivo a ser testado
	while(1)
  	{
  		//Solicitando o nome do arquivo do codigo feito pelo aluno
  		printf("\nDigite o nome do arquivo do seu codigo\n");
  		scanf("%s", nome);
  		printf("\n");
  		
  		//Verificando se esse arquivo existe
  		sprintf(comando, "%s.c", nome);
  		arquivo = fopen(comando, "r");
    	if (arquivo == NULL) 
		{
        	printf("Problema nao encontrado, a submissao deve estar na mesma pasta que o boca.\n");
        	fclose(arquivo);  // Fecha o arquivo após verificar
    	} 
		else 
		{
			fclose(arquivo);  // Fecha o arquivo após verificar
        	break;
    	}
	}
  
  	//Criando executavel para o programa a ser testado
  	sprintf(comando2, "gcc %s.c -o %s 2> a.txt", nome, nome);
  	system(comando2);

  	//Verificando se ocorreu algum erro de compilação
  	result = procurarPalavra(caminhoArquivo, palavraProcurada2);
  	if(result == 1)
  	{
    	printf("Ocorreu um erro de compilacao!\n\n");
    	return;
  	}

  	//Calculando quantos casos de teste temos
  	//Primeiramente criando um arquivo com uma lista dos arquivos em uma pasta
  	sprintf(comando1, "dir %c\\input /A-D /B", letra);
  	fp = popen(comando1, "r");
  	while (1) 
  	{
    	ch = fgetc(fp);
    	if (ch == EOF) 
    	{
      		break; //Parando de contar ao termino do arquivo
    	}
    	
    	if (ch == '\n') 
    	{
      		count++;  //contando quando uma quebra de linha aparece
    	}
  	}
  	//Fechando o arquivo
  	pclose(fp);

  	//fazendo os testes e gerando os arquivos de resultados
  	for(i = 1;i <= count; i++)
  	{
  		//Executando o codigo, inserindo a entrada e gerando o resultado em um arquivo
    	sprintf(comando, "%s < %c/input/%d.txt > %c/temp/%d.txt", nome, letra, i, letra, i);
    	system(comando);
  	}

  	//Comparando os arquivos de resultado e de saida esperada
  	for(i = 1;i <= count; i++)
  	{
  		//comparando os arquivos e gerando um arquivo com o resultado
    	sprintf(comando4, "fc /B %c\\output\\%d.txt %c\\temp\\%d.txt > a.txt", letra, i, letra, i);
    	system(comando4);
		
		//Buscando a palavra "nenhuma" no arquivo de resultado para verificar se está correto
    	result = procurarPalavra(caminhoArquivo, palavraProcurada);
	
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
  	printf("\n");
  	//Zerando a contagem
  	count = 0;
  	
  	//Deletanto o arquivo de resultado
  	system("del a.txt");
  	return;
}

//Mostrar a descrição do problema para o aluno
void MostrarProblema()
{
  	//solicitando a letra do problema
  	while (1) 
  	{
  		printf("\nDigite a letra do desafio que deseja visualizar!\n");
  		scanf(" %c", &letra);
  		
  		//Verificando se o problema existe
  		existe = pastaExiste();
    	if(existe == 0)
    	{
      		printf("\nProblema nao existente, por favor escolha corretamente\n");
    	}
    	else
    	{
      		break;
    	}
	}
	
	printf("\n");
	//abrindo o arquivo de descrição do problema
  	sprintf(caminho, "%c/quest.txt" , letra);
  	quest = fopen(caminho, "r");
  	
  	//Mostrando ele ao aluno letra a letra
  	while((letra = fgetc(quest)) != EOF)
    {
    	printf("%c",letra);
    }
    
  	fflush(stdout);//limpa buffer
  	fclose(quest);//fecha o arquivo
  	printf("\n");
  	return;
}

//Tela inicial
int main() 
{
  	while(1)
  	{
  		printf("##############################\n####### Boca Simulator #######\n##############################\n\n");

  		printf("1 - Submeter um problema\n2 - Mostrar descricao do problema\n3 - Criar um problema\n4 - Sair\n\nDigite um numero e escolha o que voce quer fazer!\n");
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
    			CriarProblema();
    			break;
    		case 4 :
    			return 0;
    			break;
    		default:
    			printf("\nEscolha invalida.\n\n");
  		}
  	}
  	return 0;
}
