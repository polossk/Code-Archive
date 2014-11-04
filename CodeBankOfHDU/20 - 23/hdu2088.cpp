#include <stdio.h>

int main(void)
{
    int n, i, s, t, c = 0;
    int a[50];

    while (scanf("%d", &n), n)
    {
        if (c++) putchar('\n');
        for (s = i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            s += a[i];
        }
        s /= n;

        for (t = i = 0; i < n; i++)
        {
            if (a[i] > s)
                t += a[i] - s;
        }
        printf("%d\n", t);        
    }

    return 0;
}
