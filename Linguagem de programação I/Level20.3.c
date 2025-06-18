#include <stdio.h>

int main()
{
	int I, A;
	scanf("%d", &I);
	scanf("%d", &A);
	
	if(I >= 65 || A >= 30 || (I >= 60 && A >+ 25))
	{
		printf("qualificado");
	}
	else
	{
		printf("desqualificado");
	}
}
