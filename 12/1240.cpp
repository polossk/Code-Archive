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

const double eps = 1e-15;
const double cef = (sqrt(5.0) - 1.0) * 0.5;

struct pnt{ double x, y, z; pnt(){ x = y = z = 0; } };

pnt A, B, C;
int t, tt;

inline double getk(const double& a, const double& b, double k)
{
    return a + (b - a) * k;
}

inline pnt getk(const pnt& a, const pnt& b, double k)
{
    pnt res;
    res.x = getk(a.x, b.x, k);
    res.y = getk(a.y, b.y, k);
    res.z = getk(a.z, b.z, k);
    return res;
}

inline double dis(const pnt& a, const pnt& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    double ds = dx * dx + dy * dy + dz * dz;
    return sqrt(ds);
}

inline bool test(double xl, double xr)
{
	// true : l = mid
	// false: r = midmid
	/**Specific Calculation**/
	pnt pl = getk(A, B, xl);
	pnt pr = getk(A, B, xr);
	double l = dis(C, pl);
	double r = dis(C, pr);
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
    A.x = nextInt(); A.y = nextInt(); A.z = nextInt();
    B.x = nextInt(); B.y = nextInt(); B.z = nextInt();
    C.x = nextInt(); C.y = nextInt(); C.z = nextInt();
    double k = Tsearch_s(0, 1);
    pnt P = getk(A, B, k);
    double ans = dis(C, P);
    printf("Case %d: %.8lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
