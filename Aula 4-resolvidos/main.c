//main.c
//Programa pra testar a ABB criada

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void PreOrdem(NoArvore *no)
{
	if(no != NULL)
	{
		printf("%d ", no->Valor);
		PreOrdem(no->Esquerda);
		PreOrdem(no->Direita);
	}
}

void PreOrdemArvore(Arvore *a)
{
	if(a != NULL)
		PreOrdem(a->Raiz);
}

void EmOrdem(NoArvore *no)
{
	if(no != NULL)
	{
		EmOrdem(no->Esquerda);
		printf("%d ", no->Valor);
		EmOrdem(no->Direita);
	}
}

void EmOrdemArvore(Arvore *a)
{
	if(a != NULL)
		EmOrdem(a->Raiz);
}

void PosOrdem(NoArvore *no)
{
	if(no != NULL)
	{
		PosOrdem(no->Esquerda);
		PosOrdem(no->Direita);
		printf("%d ", no->Valor);
	}
}

void PosOrdemArvore(Arvore *a)
{
	if(a != NULL)
		PosOrdem(a->Raiz);
}

void Desordem(NoArvore *no)
{
	if(no != NULL)
	{
		Desordem(no->Direita);
		printf("%d ", no->Valor);
		Desordem(no->Esquerda);
	}
}

void DesordemArvore(Arvore *a)
{
	if(a != NULL)
		Desordem(a->Raiz);
}

void Folhas(NoArvore *no)
{
	if(no != NULL)
	{		
		Folhas(no->Esquerda);
		
		if(no->Esquerda == NULL && no->Direita == NULL)
		{
			printf("%d ", no->Valor);
		}		
		
		Folhas(no->Direita);		
	}
}

void FolhasArvore(Arvore *a)
{
	if(a != NULL)
		Folhas(a->Raiz);
}

int Altura(NoArvore *no)
{
	if(no != NULL)
	{
		int he = Altura(no->Esquerda);
		int hd = Altura(no->Direita);
		
		if(he > hd)
			return 1 + he;
		else
			return 1 + hd;
	}
	else
		return 0;
}

int AlturaArvore(Arvore *a)
{
	if(a!=NULL)
		return Altura(a->Raiz);
	
	return 0;
}

int main(void)
{
	Arvore *a = ArvoreNovo();

	//Árvore correta
	/*
	ArvoreInserir(a, 6);
	ArvoreInserir(a, 2);
	ArvoreInserir(a, 9);
	ArvoreInserir(a, 1);
	ArvoreInserir(a, 3);
	ArvoreInserir(a, 7);
	ArvoreInserir(a, 5);
	ArvoreInserir(a, 8);
	ArvoreInserir(a, 4);
	*/
	
	//Árvore errada
	NoArvore *no6 = malloc(sizeof(NoArvore));
	no6->Valor = 6;
	
	NoArvore *no2 = malloc(sizeof(NoArvore));
	no2->Valor = 2;
	
	NoArvore *no5 = malloc(sizeof(NoArvore));
	no5->Valor = 5;
	
	NoArvore *no1 = malloc(sizeof(NoArvore));
	no1->Valor = 1;
	
	NoArvore *no3 = malloc(sizeof(NoArvore));
	no3->Valor = 3;
	
	NoArvore *no7 = malloc(sizeof(NoArvore));
	no7->Valor = 7;
	
	NoArvore *no9 = malloc(sizeof(NoArvore));
	no9->Valor = 9;
	
	NoArvore *no4 = malloc(sizeof(NoArvore));
	no4->Valor = 4;
	
	a->Raiz = no6;
	no6->Esquerda = no2;
	no6->Direita = no5;
	
	no2->Esquerda = no1;
	no2->Direita = no3;
	
	no5->Esquerda = no7;
	no5->Direita = no9;
	
	no1->Esquerda = NULL;
	no1->Direita = NULL;
	
	no3->Esquerda = NULL;
	no3->Direita = no4;
	
	no7->Esquerda = NULL;
	no7->Direita = NULL;
	
	no9->Esquerda = NULL;
	no9->Direita = NULL;
	
	no4->Esquerda = NULL;
	no4->Direita = NULL;
	
	a->Tamanho = 8;
	
	int x = 1;
	
	while(x != 0)
	{
		system("cls");
		
		printf("PRE: ");
		PreOrdemArvore(a);
				
		printf("\n EM: ");
		EmOrdemArvore(a);
				
		printf("\nPOS: ");
		PosOrdemArvore(a);
		
		printf("\nDES: ");
		DesordemArvore(a);
		
		printf("\nNos folhas: ");
		FolhasArvore(a);
		
		printf("\nAltura: %d", AlturaArvore(a));
		
		printf("\n\nTamanho: %d", a->Tamanho);
		
		printf("\n\n>> ");
		scanf("%d", &x);
		
		if(x == 0)
			break;
		
		if(x > 0)
			ArvoreInserir(a, x);
		else
			ArvoreRemover(a, -x);
	}
	
	
	return 0;
}
