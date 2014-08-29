// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   LightOJ 1042
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 MOD  = 10000007;
const int   MaxN = 10005;
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }

int t, tt, n;
int64 m[MaxN];

void solve()
{
    m[0] = nextI64(); m[1] = nextI64();
    m[2] = nextI64(); m[3] = nextI64();
    m[4] = nextI64(); m[5] = nextI64();
    n = nextInt();
    for (int i = 6; i <= n; i++)
    {
        m[i] = 0;
        m[i] = (m[i] + m[i - 1]) % MOD;
        m[i] = (m[i] + m[i - 2]) % MOD;
        m[i] = (m[i] + m[i - 3]) % MOD;
        m[i] = (m[i] + m[i - 4]) % MOD;
        m[i] = (m[i] + m[i - 5]) % MOD;
        m[i] = (m[i] + m[i - 6]) % MOD;
    }
    printf("Case %d: %d\n", ++tt, (int)(m[n] % MOD));
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
