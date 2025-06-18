#include <stdio.h>

int main() 
{
  char N[10];
  int A;
  for(A = 0; A < 10; A++)
  {
    scanf(" %c", &N[A]);
  }

  for(A = 0; A < 10; A++)
  {
    if(N[A] != 'a' && N[A] != 'e' && N[A] != 'i' && N[A] != 'o' && N[A] != 'u')
    {
      printf("%c \n", N[A]);
    }
  }
  return 0;
}