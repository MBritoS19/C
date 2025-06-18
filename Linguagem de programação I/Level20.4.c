#include <stdio.h>

int main()
{
	int N;
	char A;
	scanf("%d ", &N);
	scanf("%c", &A);
	if((N >= 75 && A == 'n')||(N >= 60 && A == 's'))
	{
		printf("aprovado");
	}
	else
	{
		printf("reprovado");
	}
	return 0;
}
