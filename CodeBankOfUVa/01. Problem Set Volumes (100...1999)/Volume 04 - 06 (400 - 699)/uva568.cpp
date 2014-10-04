//568
#include <cstdio>
int f[10001];
int main()
{
    int i, x;
    f[0] = 1;
    for (i = 1; i <= 10000; i++)
    {
        f[i] = f[i - 1] * i;
        while (f[i] % 10 == 0) f[i] /= 10;
        f[i] %= 100000;
    }
    while (~scanf("%d", &x)) 
        printf("%5d -> %d\n", x, f[x] % 10);
    return 0;
}