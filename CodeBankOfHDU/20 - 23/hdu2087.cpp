#include <stdio.h>
#include <string.h>

int main(void)
{
    int len, c;
    char *p;
    char a[1001], b[1001];

    while (scanf("%s", a), a[0] != '#')
    {
        scanf("%s", b);
        len = strlen(b);
        for (c = 0, p = a; p = strstr(p, b); c++,p += len);
        printf("%d\n", c);
    }

    return 0;
}
