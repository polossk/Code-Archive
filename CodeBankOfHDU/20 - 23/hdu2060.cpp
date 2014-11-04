#include <stdio.h>

int main(void)
{
    int t, n, s1, s2;

    scanf("%d", &t);
    while (t-- && scanf("%d%d%d", &n, &s1, &s2))
    {
        s1 += n > 6 ? 8 * (n - 6) : 0;
        s1 += n > 6 ? 27 : n * (15 - n) / 2;
        puts(s1 >= s2 ? "Yes" : "No");
    }

    return 0;
}
