#include <stdio.h>

int main()
{
  int a, t;
  scanf("%d", &a);
  t = a % 4;
  if(t > 0)
  {
    printf("nao bissexto");
  }
  else
  {
    printf("ano bissexto");
  }
}