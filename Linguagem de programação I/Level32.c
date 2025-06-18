#include <stdio.h>

int main()
{
  float N[10];
  int i;
  for(i=0;i<10;i++)
  {
    scanf("%f", &N[i]);
  }
  for(i=9;i>=0;i--)
  {
    printf("%.1f\n", N[i]);
  }
  return 0;
}