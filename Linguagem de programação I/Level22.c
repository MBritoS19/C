#include <stdio.h>

int main() 
{
  char N[100];
  int A, B;
  scanf("%s", N);
  scanf("%d", &B);
  for(A = 0; A < B; A++)
  printf("%s\n", N);
  
  return 0;
}