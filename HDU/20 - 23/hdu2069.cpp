#include <stdio.h>

int main(void)
{
    int n, d[251] = {0};
    int c1, c5, c10, c25, c50;

    for (n = 0; n < 251; n++)
    for (c50 = 0; c50 * 50 <= n; c50++)
    for (c25 = 0; c50 * 50 + c25 * 25 <= n; c25++)
    for (c10 = 0; c50 * 50 + c25 * 25 + c10 * 10 <= n; c10++)
    for (c5 = 0; c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5 <= n; c5++)
    {
        c1 = n - (c50 * 50 + c25 * 25 + c10 * 10 + c5 * 5);
        if (c1 + c5 + c10 + c25 + c50 <= 100) d[n]++;
    }
    while (scanf("%d", &n) != EOF)
        printf("%d\n", d[n]);
    return 0;
}
