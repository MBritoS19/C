#include <stdio.h>

int main()
{
  float n1, n2, n3, m;
  scanf("%f", &n1);
  scanf("%f", &n2);
  scanf("%f", &n3);
  m = (n1+n2+n3)/3;
  if(m >= 9)
  {
    printf("A");
  }
  else if(m < 9 && m >= 7.5)
  {
    printf("B");
  }
  else if(m < 7.5 && m >= 6)
  {
    printf("C");
  }
  else
  {
    printf("D");
  }
    return 0;
}