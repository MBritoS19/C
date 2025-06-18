#include <stdio.h>
#include <math.h>

int main()
{
  float N[5], R, S;
  int i;
  for(i = 0; i < 5;i++)
  {
    scanf("%f", &N[i]);
  }
  for(i = 0; i < 5;i++)
  {
    printf("%.0f\n", N[i]);
  }
  for(i = 0; i < 5;i++)
  {
    S += N[i];
  }
  R = S / 5;
  printf("%.1f", R);
  return 0;
}
