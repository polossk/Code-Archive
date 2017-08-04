#include <stdio.h>

int main(void)
{
    int i, j, n;
    __int64 d[51] = {1, 1, 2,};

    for (i = 3; i < 51; i++)
        d[i] = d[i-1] + d[i-2];
    scanf("%d", &n);
    while (n-- && scanf("%d%d", &i, &j) != EOF)
        printf("%I64d\n", i > j ? 0 : d[j-i]);

    return 0;
}
