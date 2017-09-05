#include <stdio.h>

int main(void)
{
    int t, n, c, m, i;

    scanf("%d", &t);
    while (t-- && scanf("%d%*d", &n))
    {
        for (m = 100, i = 0; i < n; i++)
        {
            scanf("%d", &c);
            if (c < m) m = c;
        }
        printf("%d\n", (100-m)*(100-m));
    }

    return 0;
}
