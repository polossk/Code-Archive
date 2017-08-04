#include <stdio.h>

int main(void)
{
    int n, i;
    double a0, an1, a1;
    double c[3000];

    while (scanf("%d", &n) != EOF)
    {
        scanf("%lf%lf", &a0, &an1);
        for (i = 0; i < n; i++)
            scanf("%lf", c + i);
        a1 = n * a0 + an1;
        for (i = 1; i <= n; i++)
            a1 -= 2 * i * c[n - i];
        printf("%.2f\n", a1 / (n + 1));
    }

    return 0;
}
