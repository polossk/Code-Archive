// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1280                                             *
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
const int MaxN = 20005;
double x[MaxN], y[MaxN], f[MaxN];
double num, den;
int n, d, k, idx[MaxN];
int t, tt;

inline bool cmp(int l, int r) { return f[l] > f[r]; }

inline double calc(double c, double nc)
{
    while (fabs(nc - c) > eps)
    {
        c = nc;
        for (int i = 0; i < n; i++)
            f[i] = x[i] - c * y[i];
        sort(idx, idx + n, cmp);
        num = den = 0;
        for (int i = 0; i < k; i++)
        {
            num += x[idx[i]];
            den += y[idx[i]];
        }
        nc = num / den;
    }
    return c;
}

void solve()
{
    n = nextInt();
    k = n - nextInt();
    for (int i = 0; i < n; i++)
    {
        x[i] = nextDbf() * 100.0;
        y[i] = nextDbf();
        idx[i] = i;
    }
    double ans = calc(0.0, 100.0);
    printf("Case %d: %.8lf\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
