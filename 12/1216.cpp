// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1216                                             *
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

const double pi = 2 * acos(0.0);
const double i3 = 1.0 / 3.0;
int t, tt;
double r1, r2, r3, x, h, p;

void solve()
{
    r1 = nextDbf(); r2 = nextDbf();
    h  = nextDbf(); p  = nextDbf();
    x  = r2 * h / (r1 - r2);
    r3 = r2 * (x + p) / x;
    double v1 = i3 * pi * r3 * r3 * (x + p);
    double v2 = i3 * pi * r2 * r2 * x;
    double vj = v1 - v2;
    printf("Case %d: %.7lf\n", ++tt, vj);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
