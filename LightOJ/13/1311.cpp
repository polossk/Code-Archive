// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1311                                             *
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

int t, tt;
double v1, v2, v3, a1, a2, s, m;

void solve()
{
    v1 = nextDbf(); v2 = nextDbf(); v3 = nextDbf();
    a1 = nextDbf(); a2 = nextDbf();
    s = v1 * v1 / a1 / 2.0 + v2 * v2 / a2 / 2.0;
    m = max(v1 / a1, v2 / a2);
    printf("Case %d: %.7lf %.7lf\n", ++tt, s, m * v3);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
