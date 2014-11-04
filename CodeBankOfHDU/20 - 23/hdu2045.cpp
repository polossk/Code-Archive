#include <math.h>
#include <stdio.h>

int main(void)
{
    int i;
    __int64 d[51] = {0, 3, 6, 6};

    for (i = 4; i < 51; i++)
        d[i] = d[i-1] + 2*d[i-2];
    while (scanf("%d", &i) != EOF)
        printf("%I64d\n", d[i]);

    return 0;
}
