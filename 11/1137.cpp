// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1137                                             *
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

const double eps = 1e-10;
const double inf = 0xfffffff;
const double PI  = acos(1.0);

double l, n, c, lp;
int t, tt;

inline bool test(double x)
{
    double angle = asin(l / x);
    double tmplp = x * angle;
    return tmplp > lp;
}

double Bsearch(double l, double r)
{
    while (r - l > eps)
    {
        double mid = (r + l) * 0.5;
        //printf("%16.4lf%16.4lf%16.4lf\n", l, mid, r);
        if (test(mid)) l = mid;
        else r = mid;
    }
    return r;
}

void solve()
{
    l = nextDbf(); n = nextDbf(); c = nextDbf();
    double ans = 0.0;
    if (n * c < eps) ans = 0.0;
    else
    {
        lp = (1.0 + n * c) * l;
        lp /= 2; l /= 2;//都除二，减少运算
        double r = Bsearch(0.0, inf);
        double h = r - sqrt(r * r - l * l);
        ans = h;
    }
    printf("Case %d: %.8lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
