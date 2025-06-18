#include <stdio.h>

int main() {
    int n1,n2,n3,x;
  
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    x = (n1 + n2 + n3) / 3;

    if (x > n1 && x > n2)
    {
    printf("maior");
    }
    else if (x > n3 && x > n1)
    {
    printf("maior");
    }
     else if (x > n3 && x > n2)
    {
    printf("maior");
    }
    else
    {
    printf("menor");
    }
    return 0;
}
