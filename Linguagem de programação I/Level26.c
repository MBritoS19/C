#include <stdio.h>

int main()
{
  int A, B = 0;
  for(A=1;A <= 100;A+=2)
  {
      B = B + A;
  }
  printf("%d", B);
  return 0;
}