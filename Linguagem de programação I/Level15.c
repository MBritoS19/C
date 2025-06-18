#include <stdio.h>

int main() {
    int n1;
  
    scanf("%d", &n1);

    n1 = n1%2;

    if (n1 > 0)
    {
    printf("impar");
    }
    else
    {
    printf("par");
    }
    return 0;
}
