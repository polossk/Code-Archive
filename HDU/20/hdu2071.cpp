#include <stdio.h>

int main(void)
{
    int t, n;
    double c, b;

    scanf("%d", &t);
    while (t-- && scanf("%d", &n))
    {
        c = 0;
        while (n-- && scanf("%lf", &b))
            if (c < b) c = b;
        printf("%.2f\n", c);
    }

    return 0;
}
