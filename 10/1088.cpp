// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1088                                             *
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


const int maxN = 100005;
int a[maxN];
int t, tt;
int n, q, x, y;

int Bsearch_lower_bound(int x)
{
    int l = 0, r = n - 1, mid = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int Bsearch_upper_bound(int x)
{
    int l = 0, r = n - 1, mid = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (a[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

void solve()
{
    n = nextInt(); q = nextInt();
    printf("Case %d:\n", ++tt);
    for (int i = 0; i < n; i++) a[i] = nextInt();
    for (int i = 0; i < q; i++)
    {
        x = nextInt(); y = nextInt();
        int l = Bsearch_lower_bound(x);
        int r = Bsearch_upper_bound(y);
        printf("%d\n", r - l);
    }
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
