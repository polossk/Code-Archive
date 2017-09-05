#include <math.h>
#include <stdio.h>

int main(void)
{
    int i;
    __int64 d[41][2] = {{0,0}, {1, 2}};

    for (i = 2; i < 41; i++)
    {
        d[i][0] = d[i-1][1];
        d[i][1] = 2 * (d[i-1][0] + d[i-1][1]);
    }
    while (scanf("%d", &i) != EOF)
        printf("%I64d\n", d[i][0] + d[i][1]);

    return 0;
}
