#include <stdio.h>

int main()
{
  long int n1, R = 1, i;
  scanf("%ld", &n1);
  for(i=1;i<=n1;i++)
  {
    R = R * i;
  }
  printf("%ld", R);
  
  return 0;
}