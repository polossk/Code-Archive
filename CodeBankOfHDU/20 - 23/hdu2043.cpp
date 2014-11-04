#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int n, a[6];
    char c;

    scanf("%d%*c", &n);
    while (n--)
    {
        a[0] = a[1] = a[2] = a[3] = a[4] = a[5] = 0;
        while ((c = getchar()) != '\n')
        {
            if (isupper(c))
                a[0] = a[5]++;
            else if (islower(c))
                a[1] = a[5]++;
            else if (isdigit(c))
                a[2] = a[5]++;
            else
                a[3] = a[5]++;
        }
        if (a[0]) a[4]++;
        if (a[1]) a[4]++;
        if (a[2]) a[4]++;
        if (a[3]) a[4]++;
        puts(a[4] > 2 && a[5] > 7 && a[5] <17 ? "YES" : "NO");
    }

    return 0;
}
