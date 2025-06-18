#include <stdio.h>

int main() {
    float n1, n2, n3, n4, m;
  
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);
    scanf("%f", &n4);
  
    m = (n1*1+n2*2+n3*3+n4*4)/(1+2+3+4);
  
    printf("%.1f\n", m);
  
    return 0;
}
