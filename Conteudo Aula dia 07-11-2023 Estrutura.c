#include <stdio.h>
#include <stdlib.h>

typedef double d;
typedef int i;
typedef unsigned long long ull;


struct ALUNO
{
	char Nome[50];
	int Idade;
	float Altura, Peso;
	char DataNascimento[11];
	
};

int main()
{
	i i,qtde;
	
	struct ALUNO MeuAluno[5];
	
	printf("Digite a Quantidade de Alunos que deseja cadastrar: ");
	scanf("%d",&qtde);
	//inserir dados no meu struct
	for(i=0;i<qtde;i++)
	{
		while((getchar()!= '\n') && (!EOF));
		printf("Digite o nome: ");
		scanf("%[^\n]",&MeuAluno[i].Nome);
		while((getchar()!= '\n') && (!EOF));
		printf("Digite a data de nascimento: ");
		scanf("%[^\n]",&MeuAluno[i].DataNascimento);
		while((getchar()!= '\n') && (!EOF));
		printf("Digite o peso: ");
		scanf("%f",&MeuAluno[i].Peso);
		printf("Digite a altura: ");
		scanf("%f",&MeuAluno[i].Altura);
		printf("Digite o idade: ");
		scanf("%d",&MeuAluno[i].Idade);
		while((getchar()!= '\n') && (!EOF));
	}
	printf("-----------------------\n");
	//Mostrando os dados
	for(i=0;i<qtde;i++)
	{
		printf("Nome: %s\nIdade: %d\nPeso: %.1f\nAltura: %.2f\nData Nascimento: %s\n\n",MeuAluno[i].Nome,MeuAluno[i].Idade,MeuAluno[i].Peso,MeuAluno[i].Altura,MeuAluno[i].DataNascimento);
	}
	
	return 0;
}
