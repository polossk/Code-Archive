// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1241                                             *
*****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

int t, tt, n, ans, a[20];

void solve()
{
    n = nextInt(); ans = 0;
    for (int i = 1; i <= n; i++) a[i] = nextInt();
    a[0] = 2;
    for (int i = 1; i <= n; i++) if (a[i] > a[i - 1])
        ans += (a[i] - a[i - 1] - 1) / 5 + 1;
    printf("Case %d: %d\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
