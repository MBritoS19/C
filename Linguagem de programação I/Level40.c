#include <stdio.h>

int main() 
{
  long int M[10], P[10], R = 1, i, f = 0;

  for(i = 0; i < 10; i++)
  {
    scanf("%ld", &M[i]);
    if(M[i] % 2 > 0)
    {
      P[f] = M[i];
      f++;
    }
  }
  for(i = 0; i < f; i++)
  {
    R *= P[i];
  }
  for(i = 0; i < f; i++)
  {
    printf("%ld\n", P[i]);
  }
  printf("%ld", R);
  return 0;
}