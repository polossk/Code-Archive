// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*@author    :   Shen                                                         *
*@name      :   LightOJ 1008                                                 *
*****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 MOD  = 10000007;
const int   MaxN = 10005;
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

int t, tt;
int64 a, b;

void solve()
{
    int64 n = nextlld();
    int64 m = (int64)sqrt(n);
    if (m * m == n) m--; n -= m * m;
    if (n <= m + 1)
        b = n, a = m + 1;
    else
        b = m + 1, a = 2 * m + 2 - n;
    if (m & 1) swap(a, b);
    printf("Case %d: %lld %lld\n", ++tt, a, b);
}

int main()
{
    t = nextInt(); while (t--) solve();
}
