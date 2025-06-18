#include <stdio.h>

int main() {
    int n1, r;
  
    scanf("%d", &n1);


    if (n1 > 20)
    {
      r = n1/2;
    printf("%d", r);
    }
    else
    {
    r = n1 * n1;
    printf("%d", r);
    }
    return 0;
}
