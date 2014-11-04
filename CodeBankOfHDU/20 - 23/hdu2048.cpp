#include <math.h>
#include <stdio.h>

int main(void)
{
    int i, n;
    __int64 d[21][2] = {{1,0},{1,0},{2,1},{6,2}};

    for (i = 4; i < 21; i++)
    {
        d[i][0] = i * d[i-1][0];
        d[i][1] = (i - 1) * (d[i-1][1] + d[i-2][1]);
    }
    scanf("%d", &n);
    while (n-- && scanf("%d", &i))
        printf("%.2f%%\n", d[i][1]*100.0/d[i][0]);

    return 0;
}
