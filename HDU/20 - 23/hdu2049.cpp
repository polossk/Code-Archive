#include <stdio.h>

int main(void)
{
    int i, m, n;
    __int64 a[21][2] = {{1,0},{1,0},{2,1},{6,2}};

    for (i = 4; i < 21; i++)
    {
        a[i][0] = i * a[i-1][0];
        a[i][1] = (i-1) * (a[i-1][1] + a[i-2][1]);
    }
    scanf("%d", &i);
    while (i-- && scanf("%d%d", &n, &m))
        printf("%I64d\n", a[n][0]/a[m][0]/a[n-m][0]*a[m][1]);

    return 0;
}
