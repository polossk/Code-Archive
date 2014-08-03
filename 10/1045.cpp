// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1045                                             *
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

const int MaxN = 1000005;
double lg[MaxN]; // log前缀和
int t, tt, n, b, ans;

void solve()
{
    n = nextInt(); b = nextInt();
    ans = (int)(lg[n] / (lg[b] - lg[b - 1])) + 1;
    printf("Case %d: %d\n", ++tt, ans);
}

int main()
{
    for (int i = 1; i < MaxN; i++) lg[i] = lg[i - 1] + log(i);
    t = nextInt(); while (t--) solve();
    return 0;
}
