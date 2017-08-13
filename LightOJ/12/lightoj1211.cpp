// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1211                                             *
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

const int INF = 0x7fffffff;
int t, tt, n, c[8];

void solve()
{
    n = nextInt();
    for (int i = 1; i < 7; i++) c[i] = (i < 4)? 0: INF;
    for (int i = 0; i < n; i++) for (int j = 1; j < 7; j++)
    {
        c[0] = nextInt();
        if (j < 4) updateMax(c[j], c[0]);
        else       updateMin(c[j], c[0]);
    }
    if (c[4] > c[1] && c[5] > c[2] && c[6] > c[3])
        c[7] = (c[4] - c[1]) * (c[5] - c[2]) * (c[6] - c[3]);
    else c[7] = 0;
    printf("Case %d: %d\n", ++tt, c[7]);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
