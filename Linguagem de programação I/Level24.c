#include <stdio.h>

int main()
{
  int A, B, C, D, E;
  scanf("%d", &A);
  scanf("%d", &B);
  C = A % 5;
  D = A - C;
  D += 5;
  for(E=D;E <= B;E+=5)
  {
    printf("%d\n", E);
  }
  return 0;
}