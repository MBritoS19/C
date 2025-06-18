#include <stdio.h>

int main() {
    float n1,c;
    char a;

    scanf("%f\n", &n1);
    scanf("%c", &a);


    if (a == 's')
    {
      c = (n1 * 1.5) * 0.85;
    printf("%.1f", c);
    }
    else
    {
    c = n1 * 1.5;
    printf("%.1f", c);
    }
    return 0;
}
