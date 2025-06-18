#include <stdlib.h>

typedef struct NoLista
{
	int Valor;
	struct NoLista *Proximo;
}NoLista;

typedef struct Lista
{
	NoLista *Primeiro;
	int Quantidade;
}Lista;

Lista *ListaNovo()
{
	Lista *L = malloc(sizeof(Lista));
	if(L != NULL)
	{
		L->Primeiro = NULL;
		L->Quantidade = 0;
	}
	
	return L;
}

int ListaInserir(Lista *L, int valor)
{
	if(L == NULL || valor <= 0)
		return 0;
		
	NoLista *no = malloc(sizeof(NoLista));
	if(no == NULL)
		return 0;
	
	no->Valor = valor;
	
	NoLista *atual = L->Primeiro;
	NoLista *anterior = NULL;
	
	while(atual != NULL && valor > atual->Valor)
	{
		anterior = atual;
		atual = atual->Proximo;
	}
	
	if(anterior == NULL)
	{
		L->Primeiro = no;
	}
	else
	{
		anterior->Proximo = no;
	}
	
	no->Proximo = atual;
	
	L->Quantidade = L->Quantidade + 1;
	
	return 1;	
}

int ListaRemover(Lista *L, int valor)
{
	if(L == NULL || valor <= 0)
		return 0;
	
	NoLista *atual = L->Primeiro;
	NoLista *anterior = NULL;
	
	while(atual != NULL && valor > atual->Valor)
	{
		anterior = atual;
		atual = atual->Proximo;
	}
	
	if(atual == NULL || atual->Valor != valor)
		return 0;
		
	//Remoção no início
	if(anterior == NULL)
		L->Primeiro = atual->Proximo;
	else 		
		anterior->Proximo = atual->Proximo; //remoção no meio ou no final
		
	free(atual);
	atual = NULL;
	L->Quantidade = L->Quantidade - 1;
	
	return 1;
}


int ListaDestruir(Lista *L)
{
	if(L == NULL)
		return 0;
	
	while(L->Primeiro != NULL)
		ListaRemover(L, L->Primeiro->Valor);
	
	free(L);
	L = NULL;
	
	return 1;
}











