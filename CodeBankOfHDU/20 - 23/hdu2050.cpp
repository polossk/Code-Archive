#include <stdio.h>

int main(void)
{
    int n, i;
    scanf("%d", &i);
    while (i-- && scanf("%d", &n))
        printf("%d\n", 2*n*n-n+1);

    return 0;
}
