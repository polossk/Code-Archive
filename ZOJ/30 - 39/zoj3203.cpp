// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   ZOJ 3203                                                 *
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

const double eps = 1e-9;
const double cef = (sqrt(5.0) - 1.0) * 0.5;
double D, H, h;

inline double calcf(double x)
{
    return D - x + H - (H - h) * D / x;
}

inline bool test(double yl, double yr)
{
    // true : l = midl
    // false: r = midr
    /**Specific Calculation**/
    return yl < yr;
}

double Tsearch_s(double l, double r)
{
    ///@return the x, not the f(x)
    double midl = r - (r - l) * cef;
    double midr = l + (r - l) * cef;
    double ansl = calcf(midl), ansr = calcf(midr);
    while (r - l > eps)
    {
        if (test(ansl, ansr))
        {
            l = midl; midl = midr; ansl = ansr;
            midr = l + r - midl; ansr = calcf(midr);
        }
        else
        {
            r = midr; midr = midl; ansr = ansl;
            midl = l + r - midr; ansl = calcf(midl);
        }
    }
    return midr;
}

void solve()
{
    H = nextDbf(); h = nextDbf(); D = nextDbf();
    double x = Tsearch_s((H - h) * D / H, D);
    printf("%.3lf\n", calcf(x));
}

int main()
{
    int t = nextInt(); while (t--) solve();
    return 0;
}
