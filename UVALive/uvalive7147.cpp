// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uvalive 7147                                             *
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

int tt, n, m;
int64 a, b, c;

void solve()
{
    n = nextInt(); m = nextInt();
    a = nextlld(); b = nextlld(); c = nextlld();
    int64 hoge = 0, piyo = 0;
    // (m), (1), (n - m - 1)
    hoge += (n - m - 1) * max(a, b);
    hoge += (m / 2) * max(b + b, a + c);
    hoge += m & 1 ? max(b, c) : 0LL;
    // (m - 1), (1), (n - m)
    piyo += (m - 1) * min(b, c);
    piyo += (n - m) / 2 * min(b + b, a + c);
    piyo += (n - m) & 1 ? min(a, b) : 0LL;
    printf("Case #%d: %lld %lld\n", ++tt, hoge, piyo);
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
// g++ A.cpp -o A.exe -std=c++11