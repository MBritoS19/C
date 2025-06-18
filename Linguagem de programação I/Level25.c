#include <stdio.h>

int main()
{
  int A, B;
  long int C = 0;
  scanf("%d", &A);
    for(B=1;B<=A;B++)
      {
        printf("%d\n", B);
        C = C + B;
      }
  printf("%ld\n", C);
  return 0;
}