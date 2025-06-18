#include <stdio.h>

int main()
{
  float N[4], Mp;
  int i;
  
  for(i = 0;i < 5; i++)
  {
    scanf("%f", &N[i]);
  }
  Mp = ((N[0] * N[2]) + (N[1] * N[3])) / (N[2] + N[3]);
  printf("%.1f\n", Mp);
  return 0;
}
