// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1062                                             *
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

const double eps = 1e-8;
int t, tt;
double x, y, c;

inline double f(double t)
{
    return c / sqrt(x * x - t * t) + c / sqrt(y * y - t * t);
}

double BSearch(double l, double r)
{
    double m = 0;
    while (r - l > eps)
    {
        m = (l + r) / 2;
        if (f(m) < 1) l = m;
        else r = m;
    }
    return l;
}

void solve()
{
    x = nextDbf(); y = nextDbf(); c = nextDbf();
    double ans = BSearch(0, min(x, y));
    printf("Case %d: %.7lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
