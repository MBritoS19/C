#include <stdio.h>

int main()
{
  float n1, n2, R;
  char o;
  scanf("%f", &n1);
  scanf("%f ", &n2);
  scanf("%c", &o);

  switch(o)
  {
    case '+':
      R = n1 + n2;
    break;
    case '-':
      R = n1 - n2;
      break;
    case '*':
      R = n1 * n2;
      break;
    case '/':
      R = n1 / n2;
      break;
  }
  printf("%.1f", R);
  return 0;
}