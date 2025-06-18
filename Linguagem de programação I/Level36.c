#include <stdio.h>

int main() 
{
  int N[5], i, tp=0,ti=0;
  for(i=0;i<5;i++)
  {
    scanf("%i", &N[i]);
    if(N[i]%2 == 0)
    {
      tp++;
    }
    else
    {
      ti++;
    }
  }
  int P[tp], I[ti], j=0, k=0;
  for(i=0; i<5;i++)
  {
    if(N[i]%2==0)
    {
      P[j] = N[i];
      j++;
    }
    else
    {
      I[k] = N[i];
      k++;
    }
  }
  for(j=0;j<tp;j++)
  {
    printf("%i\n", P[j]);
  }
  for(k=0;k<ti;k++)
  {
    printf("%i\n", I[k]);
  }
  return 0;
}