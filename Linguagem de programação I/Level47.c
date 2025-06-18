#include <stdio.h>

int adicao(int a, int b) 
{
  int c = a + b;
  return c;
}

void saida(int R)
{
  printf("%i", R);
}

int main() 
{
  int n1, n2, res;
  scanf("%i", &n1);
  scanf("%i", &n2);

  res = adicao(n1,n2);

  saida(res);
  return 0;
}