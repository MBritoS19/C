#include <stdio.h>

int main() {
    float r, a, v;
  
    scanf("%f", &r);
    scanf("%f", &a);
  
    v = 3.14 * (r * r) * a;
  
    printf("%.1f\n", v);
  
    return 0;
}
