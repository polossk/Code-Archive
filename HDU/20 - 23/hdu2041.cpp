#include <stdio.h>

int main(void)
{
    int i, n;
    __int64 m[41] = {0, 1};

    for (i = 2; i < 41; i++)
        m[i] = m[i-1] + m[i-2];

    scanf("%d", &n);
    while (n-- && scanf("%d", &i))
        printf("%I64d\n", m[i]);

    return 0;
}
