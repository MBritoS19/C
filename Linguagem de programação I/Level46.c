#include <stdio.h>

float media(float a, float b, float c) 
{
  float d = (a + b + c) / 3.0;
  return d;
}


int main() 
{
  float n1, n2, n3, res;
  scanf("%f", &n1);
  scanf("%f", &n2);
  scanf("%f", &n3);

  res = media(n1,n2,n3);

  printf("%.1f", res);

  return 0;
}