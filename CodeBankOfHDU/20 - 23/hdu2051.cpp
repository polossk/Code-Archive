#include <stdio.h>

void TtoB(int n)
{
    if (n)
    {
        TtoB(n >> 1);
        printf("%d", n & 1);
    }
}

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        TtoB(n);
        putchar('\n');
    }

    return 0;
}
