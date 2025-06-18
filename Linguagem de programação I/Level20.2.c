#include <stdio.h>

int main()
{
	int n1,n2,n3;
	
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	if(n1 >= 70 || n2 >= 75 || n3 >= 80)
	{
		printf("aprovado");
	}
	else
	{
		printf("reprovado");
	}
	return 0;
}
