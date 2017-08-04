// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1391                                             *
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

const int MaxN = 128;
const double eps = 1e-15;
const double pi  = acos(-1.0);
const double INF = 1e100;
int t, tt;
double tmp;
int n, d, s[MaxN];

double calcY(double x)
{
    double y = tmp = 0;
    for (int i = 0; i < n; i++)
    {
        y += 100 * tan(x);
        tmp += 100 / cos(x) / s[i];
        if (i == n - 1) break;
        double sn = sin(x) * s[i + 1] / s[i];
        if (sn - 1 > eps) return INF;
        x = asin(sn);
    }
    return y;
}

inline bool test(double x) { return calcY(x) - d < eps; }

double Bsearch(double l, double r)
{
    while (r - l > eps)
    {
        double mid = (r + l) / 2;
        if (test(mid)) l = mid;
        else r = mid;
    }
    return tmp;
}

void solve()
{
    n = nextInt(); d = nextInt();
    for (int i = 0; i < n; i++) s[i] = nextInt();
    double ans = Bsearch(0, pi * 0.5);
    printf("Case %d: %.8lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
