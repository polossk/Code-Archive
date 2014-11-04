#include <math.h>
#include <stdio.h>

int main(void)
{
    int i;
    __int64 d[51] = {1, 1, 2,};

    for (i = 3; i < 51; i++)
        d[i] = d[i-1] + d[i-2];
    while (scanf("%d", &i) != EOF)
        printf("%I64d\n", d[i]);

    return 0;
}
