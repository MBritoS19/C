#include <stdio.h>

int main()
{
  char T[50];
  int i,j,Ta,P=1;

  scanf("%s",T);

  Ta=0;
  while(T[Ta]!='\0') 
  {
    Ta++;
  }
  
  j=Ta - 1;
  for(i=0; i<j; i++)
	{
    if(T[i]!=T[j])
	  {
      P=0;
      break;
    }
    j--;
  }

  if(P)
	{
    printf("palindromo");
  }
	else
	{
    printf("nao palindromo");
  }
  return 0;
}
