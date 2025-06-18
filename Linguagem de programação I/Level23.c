#include <stdio.h>

int main()
{
  int A, B, C;
  long int D = 0;
  scanf("%d", &A);
  scanf("%d", &B);
    for(C=A;C<=B;C++)
      {
        D = D+ C;
      }
  printf("%ld\n", D);
  return 0;
}