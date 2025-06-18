#include <stdio.h>

int main() {
    float p1, p2, p3, i1, i2, i3;
  
    scanf("%f", &p1);
    scanf("%f", &p2);
    scanf("%f", &p3);

    i1 = (p1 / 100) * 780000;
    i2 = (p2 / 100) * 780000;
    i3 = (p3 / 100) * 780000;
  
    printf("%.1f,%.1f,%.1f\n", i1, i2, i3);
  
    return 0;
}
