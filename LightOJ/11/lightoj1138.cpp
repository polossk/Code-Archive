// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1138                                             *
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
int n, q;

inline int calc5(int x)
{
    int cnt = 0;
    while (x >= 5) { cnt += x / 5; x /= 5; }
    return cnt;
}

int Bsearch(int l, int r)
{
    int mid = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (calc5(mid) < q) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

void solve()
{
    q = nextInt();
    int ans = Bsearch(4, 500000000);
    if (calc5(ans) != q)
        printf("Case %d: impossible\n", ++tt);
    else
        printf("Case %d: %d\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
