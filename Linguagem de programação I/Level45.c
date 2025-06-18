#include <stdio.h>
#include <math.h>

int main()
{
  int i, N[5], P[5], I[5], a = 0, b = 0;
  for(i = 0; i < 5;i++)
  {
    scanf("%d", &N[i]);
    if(N[i] % 2 == 0)
    {
      P[a] = N[i];
      a++;
    }
    else
    {
      I[b] = N[i];
      b++;
    }
  }
  for(i = 0; i < a;i++)
  {
    printf("%d\n", P[i]);
  }
  for(i = 0; i < b;i++)
  {
    printf("%d\n", I[i]);
  }
  
  return 0;
}
