//arvore.h
//Contém a implementação de uma ABB (Árvore Binária de Busca)

//Representa um nó da ABB
typedef struct NoArvore
{
	int Valor;	//Valor armazenado neste nó da ABB	
	struct NoArvore *Esquerda; //Endereço de memória onde o filha à esquerda deste nós está localizado
	struct NoArvore *Direita; //Endereço de memória onde o filha à direita deste nós está localizado
}NoArvore;

//Representa uma ABB
typedef struct Arvore
{
	NoArvore *Raiz; //Endereço da raiz da ABB
	int Tamanho; //Quantidade de nós da ABB
}Arvore;

//Cria uma nova ABB e retorna o endereço de memória onde ela foi criada. Caso não haja memória suficiente, retorna nulo.
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

//Insere o valor informado na árvore informada
//Retorna 1 se a inserção foi feita com sucesso, 0 caso contrário
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

//Remover o nó que contem o valor informado da árvore informada
//Retorna 1 se remoção com sucesso, 0 cc
int ArvoreRemover(Arvore *a, int valor)
{
	if(a == NULL || a->Tamanho == 0)
		return 0;
	
	//Procurando o nó	
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
	
	//Se não existe, termina
	if(atual == NULL)
		return 0;
	
	//Se existe, decidir em qual situação ele se encontra
	if(atual->Esquerda == NULL && atual->Direita == NULL)
	{	
		//remoção de nó folha	
		if(pai == NULL)
			a->Raiz = NULL;
		else if(valor < pai->Valor)
			pai->Esquerda = NULL;
		else
			pai->Direita = NULL;
	}
	else if(atual->Esquerda != NULL && atual->Direita == NULL)
	{
		//remoção de nó apenas com filho à esquerda
		if(pai == NULL)
			a->Raiz = atual->Esquerda;
		else if(valor < pai->Valor)
			pai->Esquerda = atual->Esquerda;
		else
			pai->Direita = atual->Esquerda;
	}
	else if(atual->Esquerda == NULL && atual->Direita != NULL)
	{
		//remoção de nó apenas com filho à direita
		if(pai == NULL)
			a->Raiz = atual->Direita;
		else if(valor < pai->Valor)
			pai->Esquerda = atual->Direita;
		else
			pai->Direita = atual->Direita;
	}
	else
	{
		//remoção de nó com ambos os filhos
		
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








