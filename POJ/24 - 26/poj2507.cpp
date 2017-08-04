// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   POJ 2507                                                 *
*****************************************************************************/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

const double eps = 1e-8;
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
    double ans = BSearch(0, min(x, y));
    printf("%.3lf\n", ans);
}

int main()
{
    while (~scanf("%lf%lf%lf", &x, &y, &c)) solve();
    return 0;
}
