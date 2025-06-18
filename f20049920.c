#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define TAMANHO_MAXIMO_PALAVRA 256
#define TAMANHO_ALFABETO 26

int main()
{
    char entrada[TAMANHO_MAXIMO_PALAVRA]; // Array para armazenar a palavra de entrada do usuário
    char palavra[TAMANHO_MAXIMO_PALAVRA]; // Array para armazenar cada palavra lida do arquivo
    FILE *arquivo;                        // Ponteiro para o arquivo de palavras
    int i = 0;

    // Lê a palavra de entrada do usuário
    while (i = 0)
    {
        printf("Digite uma palavra: ");
        scanf("%s", entrada);
        if (strlen(entrada) > 0)
        {
            i = 1;
        }
        else
        {
            printf("A palavra não pode ser vazia.\n");
        }
    }
    
    // Abre o arquivo de palavras no modo leitura
    arquivo = fopen("palavras.txt", "r");
    if (!arquivo)
    {
        perror("Não foi possível abrir o arquivo palavras.txt"); // Exibe mensagem de erro se não conseguir abrir o arquivo
        return 1;                                                // Retorna 1 para indicar falha ao abrir o arquivo
    }

    // Imprime mensagem inicial
    printf("Palavras que podem ser formadas com as letras de '%s':\n", entrada);

    // Lê cada palavra do arquivo até o final
    while (fscanf(arquivo, "%s", palavra) != EOF)
    {
        // Verifica se a palavra do arquivo pode ser formada com as letras da palavra de entrada
        if (podeFormarPalavra(entrada, palavra))
        {
            printf("%s\n", palavra); // Imprime a palavra se ela pode ser formada com as letras da palavra de entrada
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0; // Retorna 0 para indicar sucesso
}
