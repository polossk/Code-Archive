#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(void)
{
    int m, n, i, t, d[500];
    
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", d + i);
		sort(d, d + n);
        for (t = i = 0; i < n / 2; i++)
            t += d[n / 2] - d[i];
        for (i++; i < n; i++)
            t += d[i] - d[n / 2];
        printf("%d\n", t);
    }
    
    return 0;
}
