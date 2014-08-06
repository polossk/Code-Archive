// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1189                                             *
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

int64 fac[21] = {1LL};
bool  vis[21] = {0};

int t, tt;

void init() { for (int64 i = 1LL; i < 21LL; i++) fac[i] = i * fac[i - 1LL]; }

void solve()
{
    int64 n = nextI64();
    fill(vis, vis + 21, 0);
    for (int i = 20; i >= 0; i--)
        if (n >= fac[i]) { vis[i] = 1; n -= fac[i]; }
    if (n != 0LL) printf("Case %d: impossible\n", ++tt);
    else
    {
        printf("Case %d: ", ++tt); int i = 0;
        for (   ; i < 21; i++) if (vis[i]) { printf("%d!", i); break; }
        for (i++; i < 21; i++) if (vis[i]) printf("+%d!", i);
        puts("");
    }
}

int main()
{
    init();
    t = nextInt(); while (t--) solve();
    return 0;
}
