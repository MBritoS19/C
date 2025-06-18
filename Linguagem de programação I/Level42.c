#include <stdio.h>

int main() 
{
  int M[3][3], i, j, d=0;
  
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      scanf("%i", &M[i][j]);
    }
  }
  for(i=0;i<3;i++)
  {
   d+=M[i][i];
  }
    printf("%i", d);
  return 0;
}