#include <stdio.h>

int main()
{
  float N[4], ma = 0;
  int i;
  for(i=0; i<4;i++)
  {
    scanf("%f", &N[i]); 
    ma+=N[i];
  }
  ma=ma/4;
  
  for(i=0;i<4;i++)
  {
    printf("%i\n", (int)N[i]);
  }
  printf("%.1f", ma);
  return 0;
}