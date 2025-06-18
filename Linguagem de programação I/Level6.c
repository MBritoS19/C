#include <stdio.h>

int main() {
    long double n1, c;
  
    scanf("%Lf", &n1);
  
    c = n1 * n1 * n1;
  
    printf("%.0Lf\n", c);
  
    return 0;
}
