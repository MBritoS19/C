#include <stdio.h>

long long int fatorial(long long int n)
{
  if(n==1)
  {
    return 1;
  }
  else
  {
    return n * fatorial(n - 1);
  }
}

int main() 
{
  long long int n1, R;
  scanf("%Ld", &n1);
  R = fatorial(n1);
  printf("%Ld", R);
}