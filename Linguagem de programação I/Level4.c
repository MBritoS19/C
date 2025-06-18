#include <stdio.h>

int main() {
    int n1, n2, a, s, m;
  
    scanf("%d", &n1);
    scanf("%d", &n2);
    a = n1 + n2;
    s = n1 - n2;
    m = n1 * n2;
  
    printf("%d,%d,%d\n", a, s, m);
  
    return 0;
}
