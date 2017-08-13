// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1202                                             *
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
int r1, c1, r2, c2, d1, d2;

void solve()
{
    r1 = nextInt(); c1 = nextInt();
    r2 = nextInt(); c2 = nextInt();
    d1 = abs(r1 - r2);
    d2 = abs(c1 - c2);
    if (d1 == d2) printf("Case %d: 1\n", ++tt);
    else if ((d1 + d2) & 1) printf("Case %d: impossible\n", ++tt);
    else printf("Case %d: 2\n", ++tt);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
