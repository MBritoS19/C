//Implementação de uma ABB(Arvore Binaria de Busca)

#include <stdlib.h>
#include <stdio.h>

//Representa o conteudo de um nó de uma ABB
typedef struct node
{
    int value; //Valor armazenado no nó
    struct node *left, *right; //Endereço de memoria para o nó a direita ou esquerda
} node;


//Representa a indicação de onde está o nó primario
typedef struct tree
{
    node *root; //endereço da raiz da arvore
    int amount; //quantidade de elementos na arvore
} tree;

//Cria uma nova arvore
tree *newTree()
{
    //Criando o ponteiro da arvore
    tree *tree = malloc(sizeof(tree));

    if(tree != NULL)
    {
        //criando o "primeiro" valor da arvore como nulo já que ele ainda não foi inserido
        tree->root = NULL;
        tree->amount = 0;
    }

    return tree;
};

//Faz a insercção de um novo valor na arvore
int insert(tree *tree, int value)
{
    //Validando se tem memoria
    if (tree == NULL)
        return 0;
    
    //Criando os valores de atual e pai para apontamento
    node *actual = tree->root;
    node *dad = NULL;

    while(actual != NULL)
    {
        dad = actual;

        if (value < actual->value)
            actual = actual->left;
        else
            actual = actual->right;
    }
    
    node *new = malloc(sizeof(node));

    if(new == NULL)
        return 0;
    
    new->value = value;
    new->left = NULL;
    new->right = NULL;

    if (dad == NULL)
        tree->root = new;
    else if(value < dad->value)
        dad->left = new;
    else
        dad->right = new;

    tree->amount++;
    return 1; 
}

//Remover o nó que contem o valor informado da árvore informada
//Retorna 1 se remoção com sucesso, 0 caso contrario
int exclude(tree *a, int value)
{
    if(a == NULL || a->amount ==0)
        return 0;

    //Procurando nó
    node *actual = a->root;
    node *dad = NULL;

    while (actual != NULL && value != actual->value)
    {
        dad = actual;

        if (value < actual->value)
        {
            actual = actual->left;
        }
        else
        {
            actual = actual->right;
        }
        
    }

    //Se não existe Termina
    if (actual == NULL)
    {
        return 0;
    }
    

    //Se existe decidir em qual estado se encontra
    if(actual->left == NULL && actual->right == NULL)
    {
        //Remoção no folha
        if (dad == NULL)
        {
            a->root = NULL;
        }
        else if (value < dad->value)
        {
            dad->left = NULL;
        }
        else 
        {
            dad->right = NULL;
        }
    }
    else if (actual->left != NULL && actual->right == NULL)
    {
        //Remoção no folha com um valor existente a esquerda
        if (dad == NULL)
        {
            a->root = actual->left;
        }
        else if (value < dad->value)
        {
            dad->left = actual->left;
        }
        else 
        {
            dad->right = actual->right;
        }    
    }
    else if (actual->left != NULL && actual->right == NULL)
    {
        //Remoção no folha com um valor existente a direita
        if (dad == NULL)
        {
            a->root = actual->right;
        }
        else if (value < dad->value)
        {
            dad->left = actual->right;
        }
        else 
        {
            dad->right = actual->left;
        }    
    }
    else
	{
		//remoção de nó com ambos os filhos
        //Encontrar o substituto
        
        node *sub = actual->left;
        node *dadsub = NULL;

        while (sub->right != NULL)
        {
            dadsub = sub;
            sub = sub->right;
        }

        dadsub->right = sub->left;
        if (actual != dadsub)
        {
            sub->right = actual->right;
            sub->left = actual->left;
        }
        

        if (dad == NULL)
        {
            a->root = sub;
        }
        else if (value < dad->value)
        {
            dad->left = sub;
        }
        else
        {
            dad->right = sub;
        } 
	}
    free(actual);
    a->amount = a->amount - 1;
    return 1;
}

//Fazendo o print da arvore em pré ordem
void printPreOrdem(node *po)
{
    if (po != NULL)
    {
        printf("%d ", po->value);
        printPreOrdem(po->left);
        printPreOrdem(po->right);
    }
}

void PreOrdemTree(tree *tree)
{
    if (tree != NULL)
        printPreOrdem(tree->root);
}

//Fazendo o print da arvore em ordem
void printEmOrdem(node *em)
{
    if (em != NULL)
    {
        printEmOrdem(em->left);
        printf("%d ", em->value);
        printEmOrdem(em->right);
    }
}

void EmOrdemTree(tree *tree)
{
    if (tree != NULL)
        printEmOrdem(tree->root);
}

//Fazendo o print da arvore em pós ordem
void printPosOrdem(node *pos)
{
    if (pos != NULL)
    {
        printPosOrdem(pos->left);        
        printPosOrdem(pos->right);
        printf("%d ", pos->value);
    }
}

void PosOrdemTree(tree *tree)
{
    if (tree != NULL)
        printPosOrdem(tree->root);
}

//Fazer o print da arvore em Ordem decrecente
void printDes(node *des)
{
     if (des != NULL)
    {
        printDes(des->right);
        printf("%d ", des->value);        
        printDes(des->left);
    }
}

void DesTree(tree *tree)
{
    if (tree != NULL)
        printDes(tree->root);
}

//Printar apenas as folhas da arvore
void PrintSheets(node *node)
{
    if (node != NULL)
    {
        PrintSheets(node->left);
        if(node->left == NULL && node->right == NULL)
        {
            printf("%d ", node->value);
        }
        PrintSheets(node->right);
    }
}

void SheetsTree(tree *tree)
{
    if (tree != NULL)
        PrintSheets(tree->root);
}

//calculo de altura
int Height(node *node)
{
    if (node != NULL)
    {
        int hl = Height(node->left);
        int hr = Height(node->right);

        if (hl > hr)
        {
            return 1 + hl;
        }
        else
        {
            return 1 + hr;
        }
        
    }
    else
        return 0;
    
}

int HeightTree(tree *tree)
{
    if (tree != NULL)
    {
        return Height(tree->root);
    }
    return 0;
}

//validar se a arvore é valida
int Validate(node *node)
{
    if (node == NULL)
        return 1;
    
    if (node->left != NULL && node->left->value >= node->value)
        return 0;

    if (node->right != NULL && node->right->value < node->value)
        return 0;
    
    return Validate(node->left) && Validate(node->right);
}

int ValidateTree(tree *tree)
{
    if (tree != NULL)
    {
        return 0;
    }
    return Validate(tree->root);
}
