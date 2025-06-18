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

	//