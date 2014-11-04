#include <stdio.h>
int main(void)
{
    int i, n;
    char c;

    scanf("%d%*c", &n);
    while (n--)
    {
        putchar('6');
        for (i = 0; i < 12; i++)
        {
            if ((c = getchar()) && i > 5)
                putchar(c);
        }
    }

    return 0;
}