#include <stdio.h>

int A(int n)
{
    int i = 1;
    while (n)
    {
        if (n % 10 == 4 || n % 100 == 62)
            return i;
        n /= 10;
        i *= 10;
    }
    return 0;
}

int main(void)
{
    int n, m, i, c, b;
    int *a = new int[1000000];

    a[0] = 0;
    for (c = 0,i = 1; i < 1000000; i += b)
    {
        b = A(i);
        if (!b) c += b = 1;
        for (n = 0; n < b; n++)
            a[i + n] = c;
    }

    while (scanf("%d%d", &n, &m), n + m)
        printf("%d\n", a[m] - a[n-1]);

    return 0;
}