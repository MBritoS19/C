#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void ExibirLista(Lista *L)
{
	NoLista *no = L->Primeiro;
	
	while(no != NULL)
	{
		printf("%d ", no->Valor);
		no = no->Proximo;
	}
}

int main(void)
{	
	Lista *L = ListaNovo();
	
	int x = 1;
	
	while(x != 0)
	{
		system("cls");
		
		ExibirLista(L);
		
		printf("\n\n>> ");
		scanf("%d", &x);
		
		if(x > 0)
			ListaInserir(L, x);
		else if(x < 0)
			ListaRemover(L, -x);
	}
	
	ListaDestruir(L);
	return 0;
}

