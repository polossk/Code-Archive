#include <stdio.h>

int main(void)
{
    __int64 n;
    int c, t;
    int d[] = {
         4, 8,16,32,64,28,56,12,24,48,
        96,92,84,68,36,72,44,88,76,52
    };

    while (scanf("%d", &t), t)
    {
        for (c = 1; c <= t; c++)
        {
            scanf("%I64d", &n);
            printf("Case %d: %d\n", c, n<3?(n<2?2:6):(d[(2*n-4)%20]+d[(n-3)%20])%100);
        }
        putchar('\n');
    }

    return 0;
}
