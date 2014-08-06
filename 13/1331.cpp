// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1331                                             *
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

double calcAngle(double a, double b, double c)
{
    return acos((a * a + b * b - c * c) / (2.0 * a * b));
}

double calcS(double a, double b, double c)
{
    double p = 0.5 * (a + b + c);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int t, tt;
double r1, r2, r3;

void solve()
{
    r1 = nextDbf(); r2= nextDbf(); r3 = nextDbf();
    double a = r1 + r2;
    double b = r2 + r3;
    double c = r3 + r1;
    double s = calcS(a, b, c);
    s -= r1 * r1 * 0.5 * calcAngle(c, a, b);
    s -= r2 * r2 * 0.5 * calcAngle(a, b, c);
    s -= r3 * r3 * 0.5 * calcAngle(b, c, a);
    printf("Case %d: %.7lf\n", ++tt, s);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
