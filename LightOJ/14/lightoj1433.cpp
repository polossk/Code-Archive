// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1433                                             *
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

typedef complex<double> pnt;
#define x real()
#define y imag()

double dis2(const pnt& a, const pnt& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int t, tt;
pnt a, b, o;

void solve()
{
    o.x = nextDbf(); o.y = nextDbf();
    a.x = nextDbf(); a.y = nextDbf();
    b.x = nextDbf(); b.y = nextDbf();
    double sa = dis2(o, a);
    double sb = dis2(o, b);
    double sc = dis2(a, b);
    double rs = (sa + sb - sc) / (2 * sqrt(sa * sb));
    double ans = acos(rs) * sqrt(sa);
    printf("Case %d: %lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
