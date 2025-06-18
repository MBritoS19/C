//arvore.h
//Cont�m a implementa��o de uma ABB (�rvore Bin�ria de Busca)

//Representa um n� da ABB
typedef struct NoArvore
{
	int Valor;	//Valor armazenado neste n� da ABB	
	struct NoArvore *Esquerda; //Endere�o de mem�ria onde o filha � esquerda deste n�s est� localizado
	struct NoArvore *Direita; //Endere�o de mem�ria onde o filha � direita deste n�s est� localizado
}NoArvore;

//Representa uma ABB
typedef struct Arvore
{
	NoArvore *Raiz; //Endere�o da raiz da ABB
	int Tamanho; //Quantidade de n�s da ABB
}Arvore;

//Cria uma nova ABB e retorna o endere�o de mem�ria onde ela foi criada. Caso n�o haja mem�ria suficiente, retorna nulo.
Arvore* ArvoreNovo()
{
	Arvore *a = malloc(sizeof(Arvore));
	
	if(a != NULL)
	{
		a->Raiz = NULL;
		a->Tamanho = 0;
	}
	
	return a;
}

//Insere o valor informado na �rvore informada
//Retorna 1 se a inser��o foi feita com sucesso, 0 caso contr�rio
int ArvoreInserir(Arvore *a, int valor)
{
	if(a == NULL)
		return 0;
		
	NoArvore *atual = a->Raiz;
	NoArvore *pai = NULL;
	
	while(atual != NULL)
	{
		pai = atual;
		
		if(valor < atual->Valor)
			atual = atual->Esquerda;
		else
			atual = atual->Direita;
	}
	
	NoArvore *novo = malloc(sizeof(NoArvore));
	if(novo == NULL)
		return 0;
	
	novo->Valor = valor;
	novo->Esquerda = NULL;
	novo->Direita = NULL;
	
	if(pai == NULL)
		a->Raiz = novo;
	else if(valor < pai->Valor)
		pai->Esquerda = novo;
	else
		pai->Direita = novo;
		
	a->Tamanho = a->Tamanho + 1;
	return 1;
}

//Remover o n� que contem o valor informado da �rvore informada
//Retorna 1 se remo��o com sucesso, 0 cc
int ArvoreRemover(Arvore *a, int valor)
{
	if(a == NULL || a->Tamanho == 0)
		return 0;
	
	//Procurando o n�	
	NoArvore *atual = a->Raiz;
	NoArvore *pai = NULL;
	
	while(atual != NULL && valor != atual->Valor)
	{
		pai = atual;
		
		if(valor < atual->Valor)
			atual = atual->Esquerda;
		else
			atual = atual->Direita;
	}
	
	//Se n�o existe, termina
	if(atual == NULL)
		return 0;
	
	//Se existe, decidir em qual situa��o ele se encontra
	if(atual->Esquerda == NULL && atual->Direita == NULL)
	{	
		//remo��o de n� folha	
		if(pai == NULL)
			a->Raiz = NULL;
		else if(valor < pai->Valor)
			pai->Esquerda = NULL;
		else
			pai->Direita = NULL;
	}
	else if(atual->Esquerda != NULL && atual->Direita == NULL)
	{
		//remo��o de n� apenas com filho � esquerda
		if(pai == NULL)
			a->Raiz = atual->Esquerda;
		else if(valor < pai->Valor)
			pai->Esquerda = atual->Esquerda;
		else
			pai->Direita = atual->Esquerda;
	}
	else if(atual->Esquerda == NULL && atual->Direita != NULL)
	{
		//remo��o de n� apenas com filho � direita
		if(pai == NULL)
			a->Raiz = atual->Direita;
		else if(valor < pai->Valor)
			pai->Esquerda = atual->Direita;
		else
			pai->Direita = atual->Direita;
	}
	else
	{
		//remo��o de n� com ambos os filhos
		
		//Encontrar o substituto
		NoArvore *substituto = atual->Esquerda;
		NoArvore *paiSubstistuto = atual;
		
		while(substituto->Direita != NULL)
		{
			paiSubstistuto = substituto;
			substituto = substituto->Direita;
		}
		
		substituto->Direita = atual->Direita;
		
		if(atual != paiSubstistuto)
		{		
			paiSubstistuto->Direita = substituto->Esquerda;
			substituto->Esquerda = atual->Esquerda;
		}
	
		if(pai == NULL)
			a->Raiz = substituto;
		else if(valor < pai->Valor)
			pai->Esquerda = substituto;
		else
			pai->Direita = substituto;		
	}
	
	free(atual);
	a->Tamanho = a->Tamanho - 1;
	return 1;
}








