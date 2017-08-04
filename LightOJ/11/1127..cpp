// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1127                                             *
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

const int MaxN = 32;
const int MaxL = (1 << 16) + 32;
int t, tt, n;
int64 a[MaxL], b[MaxL];
int64 w, ans, p[MaxL];

void solve()
{
    ans = 0;
    n = nextInt(); w = nextlld();
    fill(a, a + MaxL, 0LL);
    fill(b, b + MaxL, 0LL);
    fill(p, p + MaxL, 0LL);
    for (int i = 0; i < n; i++) p[i] = nextlld();
    int pa = n >> 1, pb = n - pa;
    int l = 1 << pa, r = 1 << pb;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < pa; j++)
            a[i] += (i & (1 << j))? p[j]: 0LL;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < pb; j++)
            b[i] += (i & (1 << j))? p[pa + j]: 0LL;
    sort(b, b + r);
    for (int i = 0; i < l; i++) if (w - a[i] >= 0)
        ans += upper_bound(b, b + r, w - a[i]) - b;
    printf("Case %d: %lld\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
