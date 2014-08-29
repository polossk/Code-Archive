// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   I
******************************************************************************/
//Memory: 356K		Time: 438MS
#include <cstdio>
using namespace std;

int n, m, k, j, ans1, ans2;

inline int Joseph(int n, int m, int k)
{
    int t = (n - k + m) % (n - k + 1);
    for (int i = (n - k + 2); i <= n; ++i)
        t = (m + t) % i;
    return t;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &j); --j;
    ans1 = Joseph(n + 1, m, k) + 1;
    while (true)
    {
        int t = n - ans2 + 1;
        if (j != (t + m - 1) % t) { ++ans2; j = (j + t - m) % t; }
        else break;
    }++ans2;
    printf("%d %d\n", ans1, ans2);
    return 0;
}
