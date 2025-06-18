// Programa para testar a arvore

#include <stdlib.h>
#include <stdio.h>
#include "Arvore.h"

int main()
{
    // Menu inicial
    int Exit = 0;
    tree *tree = newTree();
    printf("Parabens!!\n");
    printf("Sua arvore foi criada com sucesso\n");
    int value = 0;

    // O menu vai repetir até que seja inserido o value para saida
    while (Exit != 3)
    {
         insert(tree, 6);
         insert(tree, 2);
         insert(tree, 1);
         insert(tree, 3);
         insert(tree, 5);
         insert(tree, 4);
         insert(tree, 9);
         insert(tree, 7);
         insert(tree, 8);

        //Árvore errada
//        node *no6 = malloc(sizeof(node));
//        no6->value = 6;
//        
//        node *no2 = malloc(sizeof(node));
//        no2->value = 2;
//        
//        node *no5 = malloc(sizeof(node));
//        no5->value = 5;
//        
//        node *no1 = malloc(sizeof(node));
//        no1->value = 1;
//        
//        node *no3 = malloc(sizeof(node));
//        no3->value = 3;
//        
//        node *no7 = malloc(sizeof(node));
//        no7->value = 7;
//        
//        node *no9 = malloc(sizeof(node));
//        no9->value = 9;
//        
//        node *no4 = malloc(sizeof(node));
//        no4->value = 4;
//        
//        tree->root = no6;
//        no6->left = no2;
//        no6->right = no5;
//        
//        no2->left = no1;
//        no2->right = no3;
//        
//        no5->left = no7;
//        no5->right = no9;
//        
//        no1->left = NULL;
//        no1->right = NULL;
//        
//        no3->left = NULL;
//        no3->right = no4;
//        
//        no7->left = NULL;
//        no7->right = NULL;
//        
//        no9->left = NULL;
//        no9->right = NULL;
//        
//        no4->left = NULL;
//        no4->right = NULL;
//
//
//
    	system("cls");
        // escolhendo a opção
        printf("Quantidade total de elementos: %d \n\n", tree->amount);

        printf("\nElementos atuais em pre ordem:\n");
        PreOrdemTree(tree);

        printf("\nElementos atuais em ordem:\n");
        EmOrdemTree(tree);

        printf("\nElementos atuais em pos ordem:\n");
        PosOrdemTree(tree);

        printf("\nElementos atuais em ordem decrecente:\n");
        DesTree(tree);

        printf("\nTodas as folhas da arvore:\n");
        SheetsTree(tree);

        printf("\nAltura da arvore:\n");
        int Height = HeightTree(tree);
        printf("%d\n", Height);

        if (ValidateTree(tree))
        {
            printf("\nArvore Valida\n");
        }
        else
        {
            printf("\nArvore Invalida\n");
        }

        printf("\nPor favor escolha a opcao desejada:\n1-Inserir um novo valor na arvore atual\n2-Excluir um elemento na arvore\n3-Sair\n");
        scanf("%d", &Exit);
        printf("\n");

        switch (Exit)
        {
        case 1:
            printf("\nPor favor escreva um numero diferente e maior que 0 a ser adicionado na arvore\n");
            scanf("%d", &value);
            insert(tree, value);
            break;

        case 2:
            printf("\nPor favor escreva um numero existente na arvore para Exclusao\n");
            scanf("%d", &value);
            int teste = exclude(tree, value);
            if(teste = 0)
            {
                printf("\nVish deu erro\n");
            }
            
            break;

        case 3:
            printf("Processo finalizado\n");
            printf("Arvore criada excluida");
            break;

        default:
            printf("Opcao incorreta, por favor inserir uma opcao valida");
            break;
        }
    };

    return 0;
}
