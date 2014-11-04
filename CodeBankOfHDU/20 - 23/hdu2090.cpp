#include <stdio.h>

int main(void)
{
    double sum = 0, d, n;

    while (scanf("%*s") != EOF)
    {
        scanf("%lf%lf", &n, &d);
        sum += n * d;
    }
    printf("%.1f\n", sum);

    return 0;
}
