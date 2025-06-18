#include <stdio.h>

int main() 
{
  int M[5], R = 1, i;

  for(i = 0; i < 5; i++)
  {
    scanf("%d", &M[i]);
  }
  for(i = 0; i < 5; i++)
  {
    R *= M[i];
  }
  for(i = 0; i < 5; i++)
  {
    printf("%d\n", M[i]);
  }
  printf("%d", R);
  return 0;
}