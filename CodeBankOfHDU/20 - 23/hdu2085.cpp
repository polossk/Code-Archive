#include <stdio.h>

int main(void)
{
    int n, i;
    __int64 g[34] = {1};
    __int64 d[34] = {0};

    for (i = 1; i < 34; i++)
    {
        g[i] = 3 * g[i - 1] + 2 * d[i - 1];
        d[i] = g[i - 1] + d[i - 1];
    }

    while (scanf("%d", &n), n != -1)
        printf("%I64d, %I64d\n", g[n], d[n]);

    return 0;
}
