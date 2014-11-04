#include <stdio.h>

int main()
{
    int n, m, i;

    while (scanf("%d%d", &m, &n), m+n)
    {
        for (i = 1; n/i-(i-1)/2>0; i++);
        for(i--; i && n/i+i/2 <= m; i--)
        {
            if((n-n/i*i)*2 == i)
                printf("[%d,%d]\n", n/i-(i-1)/2, n/i+i/2);
            if(!(n%i) && i%2)
                printf("[%d,%d]\n", n/i-(i-1)/2, n/i+i/2);
        }
        putchar('\n');
    }
    return 0;
}
