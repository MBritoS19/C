#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO_PALAVRA 256
#define TAMANHO_ALFABETO 26

// Função para contar a frequência das letras em uma palavra
void contarLetras(const char *palavra, int *contagem)
{
    // Inicializa o array contagem com zeros
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
    {
        contagem[i] = 0;
    }

    // Percorre a palavra e incrementa o contador da letra correspondente
    // 'a' - 'a' resulta em 0, 'b' - 'a' resulta em 1, ..., 'z' - 'a' resulta em 25
    while (*palavra)
    {
        contagem[*palavra - 'a']++;
        palavra++;
    }
}

// Função para verificar se uma palavra pode ser formada com as letras de outra palavra
int podeFormarPalavra(const char *entrada, const char *palavra)
{
    int contagemEntrada[TAMANHO_ALFABETO] = {0}; // Array para contar as letras da palavra de entrada
    int contagemPalavra[TAMANHO_ALFABETO] = {0}; // Array para contar as letras da palavra do arquivo
    
    // Conta as letras da palavra de entrada
    contarLetras(entrada, contagemEntrada);
    // Conta as letras da palavra do arquivo
    contarLetras(palavra, contagemPalavra);

    // Verifica se cada letra da palavra de entrada está presente na palavra do arquivo
    // em quantidade igual ou maior
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
    {
        if (contagemEntrada[i] > 0 && contagemPalavra[i] < contagemEntrada[i])
        {
            return 0; // A palavra do arquivo contém menos ocorrências de uma letra do que a palavra de entrada
        }
        if (contagemEntrada[i] == 0 && contagemPalavra[i] > 0)
        {
            return 0; // A palavra do arquivo contém uma letra que não está na palavra de entrada
        }
    }

    return 1; // Retorna verdadeiro se a palavra do arquivo pode ser formada com as letras da palavra de entrada
}
