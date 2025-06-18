#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ALFABETO 26
#define TAMANHO_MAXIMO_PALAVRA 50

// Estrutura do nó da Trie
typedef struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    int fimDaPalavra;
} NoTrie;

// Função para criar um novo nó da Trie
NoTrie* obterNo() {
    NoTrie* no = (NoTrie*)malloc(sizeof(NoTrie));
    no->fimDaPalavra = 0;
    int i;
    for (i = 0; i < TAMANHO_ALFABETO; i++) {
        no->filhos[i] = NULL;
    }
    return no;
}

// Função para inserir uma palavra na Trie
void inserir(NoTrie* raiz, const char* palavra) {
    NoTrie* atual = raiz;
    while (*palavra) {
        int indice = *palavra - 'a';
        if (!atual->filhos[indice]) {
            atual->filhos[indice] = obterNo();
        }
        atual = atual->filhos[indice];
        palavra++;
    }
    atual->fimDaPalavra = 1;
}

// Função para buscar uma palavra na Trie
int buscar(NoTrie* raiz, const char* palavra) {
    NoTrie* atual = raiz;
    while (*palavra) {
        int indice = *palavra - 'a';
        if (!atual->filhos[indice]) {
            return 0;
        }
        atual = atual->filhos[indice];
        palavra++;
    }
    return atual && atual->fimDaPalavra;
}

// Função auxiliar para gerar permutações e verificar na Trie
void permutarEVerificar(char* str, int l, int r, NoTrie* raiz) {
    if (l == r) {
        if (buscar(raiz, str)) {
            printf("%s Válida\n", str);
        } else {
            printf("%s Inválida\n", str);
        }
    } else {
        int i;
        for (i = l; i <= r; i++) {
            if (i != l && str[i] == str[l]) continue;  // Evitar permutações redundantes
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;
            permutarEVerificar(str, l + 1, r, raiz);
            str[i] = str[l];  // backtrack
            str[l] = temp;    // backtrack
        }
    }
}

int main() {
    char letras[TAMANHO_MAXIMO_PALAVRA];

    // Criar a raiz da Trie
    NoTrie* raiz = obterNo();

    // Carregar palavras válidas do arquivo palavras.txt na Trie
    FILE* arquivoPalavras = fopen("palavras.txt", "r");
    if (arquivoPalavras == NULL) {
        printf("Erro ao abrir o arquivo de palavras.\n");
        return 1;
    }

    char palavra[TAMANHO_MAXIMO_PALAVRA];
    while (fgets(palavra, TAMANHO_MAXIMO_PALAVRA, arquivoPalavras)) {
        // Remover caractere de nova linha
        palavra[strcspn(palavra, "\n")] = 0;
        inserir(raiz, palavra);
    }
    fclose(arquivoPalavras);

    // Obter letras do usuário
    printf("Digite um conjunto de letras: \n");
    if (scanf("%s", letras) != 1) {
        printf("Erro ao ler as letras.\n");
        return 1;
    }

    // Gerar permutações e verificar palavras válidas
    int len = strlen(letras);
    permutarEVerificar(letras, 0, len - 1, raiz);

    // Pausa antes de sair do programa
    printf("Pressione qualquer tecla para sair...");
    getchar(); // Consumir a nova linha deixada pelo scanf
    getchar(); // Esperar por uma tecla

    return 0;
}
