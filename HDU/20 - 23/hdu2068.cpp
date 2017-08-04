#include <stdio.h>

int main(void)
{
    int i, n;
    double s;
    double d[26][2] = {{1,1},{1,0},{2,1},{6,2}};
    
    for (i = 4; i < 26; i++)
    {
        d[i][0] = i * d[i-1][0];
        d[i][1] = (i - 1) * (d[i-1][1] + d[i-2][1]);
    }
    while (scanf("%d", &n), n)
    {
        for (s = 0, i = n/2; i >= 0; i--)
            s += 1.0*d[n][0]/d[i][0]/d[n-i][0]*d[i][1];
        printf("%.lf\n", s);
    }
}
