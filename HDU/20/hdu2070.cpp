#include <stdio.h>

int main(void)
{
    int i;
    __int64 f[51]={0, 1};

    for(i = 2; i < 51; i++)
        f[i] = f[i-1] + f[i-2];

    while(scanf("%d", &i), i + 1)
        printf("%I64d\n", f[i]);

    return 0;
}
