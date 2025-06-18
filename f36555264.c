#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define ALPHABET_SIZE 26

// Função para contar a frequência das letras em uma palavra
void countLetters(const char *word, int *count) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        count[i] = 0;
    }
    while (*word) {
        count[*word - 'a']++;
        word++;
    }
}

// Função para verificar se uma palavra pode ser formada com as letras de outra palavra
int canFormWord(const char *input, const char *word) {
    int inputCount[ALPHABET_SIZE] = {0};
    int wordCount[ALPHABET_SIZE] = {0};
    
    countLetters(input, inputCount);
    countLetters(word, wordCount);
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (inputCount[i] > 0 && wordCount[i] < inputCount[i]) {
            return 0; // A palavra contém menos ocorrências de uma letra do que a palavra de entrada
        }
        if (inputCount[i] == 0 && wordCount[i] > 0) {
            return 0; // A palavra contém uma letra que não está na palavra de entrada
        }
    }
    
    return 1;
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *file;

    // Lê a palavra de entrada
    printf("Digite uma palavra: ");
    scanf("%s", input);

    // Abre o arquivo de palavras
    file = fopen("palavras.txt", "r");
    if (!file) {
        perror("Não foi possível abrir o arquivo palavras.txt");
        return 1;
    }

    printf("Palavras que podem ser formadas com as letras de '%s':\n", input);

    // Lê cada palavra do arquivo e verifica se pode ser formada com as letras da palavra de entrada
    while (fscanf(file, "%s", word) != EOF) {
        if (canFormWord(input, word)) {
            printf("%s\n", word);
        }
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}
