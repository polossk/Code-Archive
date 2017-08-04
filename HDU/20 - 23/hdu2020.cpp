#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b)
{
    return abs(a) > abs(b);
}

int main(void)
{
    int n, i, x[101];
    
    while (scanf("%d", &n), n)
    {
        for (i = 0 ; i < n ; i++)
            scanf("%d", x + i);
        sort(x, x + n, cmp);
        for (i = 0 ; i < n ; i++)
            printf("%d%c", x[i], (i != n - 1 ? ' ' : '\n'));
    }

    return 0;
}
