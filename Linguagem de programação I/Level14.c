#include <stdio.h>

int main() {
    int n1,n2,x;
  
    scanf("%d", &n1);
    scanf("%d", &n2);

    x = (n1 + n2) / 2;

    if (x >= 6)
    {
    printf("aprovado");
    }
    else
    {
    printf("reprovado");
    }
    return 0;
}
