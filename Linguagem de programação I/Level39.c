#include <stdio.h>

int main() 
{
  int M[10], P[10] = {0,0,0,0,0,0,0,0,0,0}, R = 0, i, f = 0;

  for(i = 0; i < 10; i++)
  {
    scanf("%d", &M[i]);
    if(M[i] % 2 == 0)
    {
      P[f] = M[i];
      f++;
    }
  }
  for(i = 0; i < 10; i++)
  {
    R += P[i];
  }
  for(i = 0; i < f; i++)
  {
    printf("%d\n", P[i]);
  }
  printf("%d", R);
  return 0;
}