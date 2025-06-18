#include <stdio.h>

int main() 
{
  int A, B, C, D;
  scanf("%d", &A);
  D = A;
  scanf("%d", &B);
  for(C = 1;C < B;C++)
  {
    D = D * A;
  }
  printf("%d", D);
  return 0;
}