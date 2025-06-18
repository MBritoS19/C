#include<stdio.h>

float Me(int N1, int N2)
{
	float ma=0.0;
	ma=(float)(N1+N2)/2;
	return ma;
}

int main()
{
	int N[4][2], i, j;
	float M[4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%i", &N[i][j]);
		}
	}
	
	for(i=0;i<4;i++)
	{
		M[i] = Me(N[i][0], N[i][1]);
	}
	
	for(i=0;i<4;i++)
	{
		printf("%.1f\n", M[i]);
	}
	return 0;
}
