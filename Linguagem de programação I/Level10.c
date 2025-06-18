#include <stdio.h>

int main() {
    float SB, SL, INSS, H;
  
    scanf("%f", &H);

    SB = H * 3;
    INSS = ((SB * 8) / 100);
    SL = SB - INSS;
  
    printf("%.1f\n", SL);
  
    return 0;
}
