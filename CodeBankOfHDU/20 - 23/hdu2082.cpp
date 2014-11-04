#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, t, x;
    int n[2][51];

    scanf("%d", &t);
    while (t--)
    {
        memset(n[0], 0, sizeof(n[0]));
        n[0][0] = 1;
        for (i = 1; i < 27; i++)
        {
            scanf("%d", &x);
            if (!x)
            {
                for (j = 0; j < 51; j++)
                    n[i % 2][j] = n[!(i%2)][j];
                continue;
            }
            memset(n[i % 2], 0, sizeof(n[0]));
            for (j = 0; j < 51 && j <= x * i; j += i)
            {
                for (k = 0; k + j < 51 ; k++)
                {
                    if (n[!(i%2)][k])
                        n[i % 2][k + j] += n[!(i%2)][k];
                }
            }
        }
        for (x = 0, i = 1; i < 51; i++)
            x += n[0][i];
        printf("%d\n", x);
    }

    return 0;
}

