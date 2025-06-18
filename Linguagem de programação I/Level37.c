#include <stdio.h>

int main() 
{
  int N[5], i, R = 0;
  for(i = 0; i < 5; i++)
  {
    scanf("%d", &N[i]);
  }
  for(i = 0; i < 5; i++)
  {
    R += N[i];
  }
  for(i = 0; i < 5; i++)
  {
    printf("%d\n", N[i]);
  }
  printf("%d", R);
  return 0;
}