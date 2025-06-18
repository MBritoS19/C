#include <stdio.h>

int main() 
{
  int X[5], A;
  for(A = 0;A < 5;A++)
  {
     scanf("%d", &X[A]);
  }
  for(A = 0;A < 5;A++)
  {
     printf("%d\n", X[A]);
  }
  return 0;
}
