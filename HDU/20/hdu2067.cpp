#include <stdio.h>

int main(void)
{
    int i, j;
    __int64 a[36] = {1};
    __int64 b[36] = {0};
    for (i = 1; i < 36; i++)
    {
        for (j = 1; j < i; j++)
            a[j] += a[j-1];
        b[i] = a[i] = a[i-1];
    }

    for (j = 1; scanf("%d", &i), i+1; j++)
        printf("%d %d %I64d\n",j, i, 2 * b[i]);
    
    return 0;
}
