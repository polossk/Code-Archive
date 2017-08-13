// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1146                                             *
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

const double eps = 1e-15;
const double cef = (sqrt(5.0) - 1.0) * 0.5;

typedef complex<double> pnt;
#define x real()
#define y imag()

pnt a, b, c, d;
int t, tt;

inline double dis(const pnt& a, const pnt& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double ds = dx * dx + dy * dy;
    return sqrt(ds);
}

inline bool test(double xl, double xr)
{
	// true : l = mid
	// false: r = midmid
	/**Specific Calculation**/
	pnt pl1 = a + (b - a) * xl;
	pnt pl2 = a + (b - a) * xr;
	pnt pr1 = c + (d - c) * xl;
	pnt pr2 = c + (d - c) * xr;
	double l = dis(pl1, pr1);
	double r = dis(pl2, pr2);
	return l - r >= eps;
}
double Tsearch_s(double l, double r)
{
    ///@return the x, not the f(x)
    double midl = r - (r - l) * cef;
    double midr = l + (r - l) * cef;
    while (r - l > eps)
    {
        if (test(midl, midr))
        {
            l = midl; midl = midr;
            midr = l + (r - l) * cef;
        }
        else
        {
            r = midr; midr = midl;
            midl = r - (r - l) * cef;
        }
    }
    return midr;
}

void solve()
{
    a.x = nextInt(); a.y = nextInt();
    b.x = nextInt(); b.y = nextInt();
    c.x = nextInt(); c.y = nextInt();
    d.x = nextInt(); d.y = nextInt();
    double k = Tsearch_s(0, 1);
    pnt p1 = a + (b - a) * k;
    pnt p2 = c + (d - c) * k;
    double ans = dis(p1, p2);
    printf("Case %d: %.8lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
