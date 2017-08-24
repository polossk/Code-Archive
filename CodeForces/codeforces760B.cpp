// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #393 (Div. 2) B                         *
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

int64 n, m, k;

bool judge(int64 x)
{
    int64 used = 0;
    // left side
    if (k < x) used += (x + x - k + 1) * k / 2;
    else used += (k - x) + (x + 1) * x / 2;
    // right side
    if (x > n - k + 1) used += (x + x - n + k) * (n - k + 1) / 2;
    else used += (n - k + 1 - x) + (x + 1) * x / 2;
    used -= x;
    // cout << x << " " << used << " " << m << " " << (used > m) << endl;
    return used > m;
}

int64 bsearch(int64 l, int64 r)
{
    while (r > l)
    {
        int64 mid = l + (r - l) / 2;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    // cout << l << " " << r << endl;
    return l;
}


int main()
{
    cin >> n >> m >> k;
    int64 d = bsearch(1, m);
    for (int64 i = d + 2; i >= d - 2; i--)
    {
        if (!judge(i)) { cout << i << endl; return 0; }
    }
    return 0;
}