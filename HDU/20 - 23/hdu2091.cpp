#include <stdio.h>

int main(void)
{
    char c;
    int i = 0, n;

    while ((c = getchar()) != '@')
    {
        scanf("%d%*c", &n);
        printf(i ? "\n%*c\n" : "%*c\n", n, c);
        if (n == 1) 
        {
            i = 1;
            continue;
        }
        for (i = 1; i + 1 < n; i++)
            printf("%*c%*c\n", n - i, c, i * 2, c);
        for (i = 0; i < 2 * n - 1; i++)
            putchar(c);
        putchar('\n');
    }
    return 0;
}
