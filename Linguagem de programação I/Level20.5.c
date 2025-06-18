#include <stdio.h>

int main()
{
	float L, T;
	char C;
	
	scanf("%f ", &L);
	scanf("%c", &C);
	
	if(L <= 20 && C == 'e')
	{
		T = (L * 3.9) * 0.97;
	}
	else if(L > 20 && C == 'e')
	{
		T = (L * 3.9) * 0.95;
	}
	else if(L <= 20 && C == 'g')
	{
		T = (L * 5) * 0.96;
	}
	else if(L > 20 && C == 'g')
	{
		T = (L * 5) * 0.94;
	}
	printf("%.1f", T);
	return 0;
}
