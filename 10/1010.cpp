// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*@author    :   Shen                                                         *
*@name      :   LightOJ 1010                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
inline int    nextInt() { int x; scanf("%d", &x); return x; }

int t, tt, n, m, res, ans;

void solve()
{
    n = nextInt(); m = nextInt();
    res = max(n, m);
    if (n == 1 || m == 1)
        ans = res;
    else if (n == 2|| m == 2)
    {
        if (res % 4 == 1)      ans = res / 4 * 4 + 2;
        else if (res % 4 == 0) ans = res;
        else                   ans = res / 4 * 4 + 4;
    }
    else ans = ((m * n) % 2 == 0)? m * n / 2: m * n / 2 + 1;
    printf("Case %d: %d\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
