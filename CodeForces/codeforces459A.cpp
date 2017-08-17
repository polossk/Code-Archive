// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   A                                                        *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

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
int a1, b1, a2, b2;
int a3, b3, a4, b4;

void solve()
{
    if (a1 == a2 && b1 != b2)
    {
        a3 = a4 = a1 + abs(b1 - b2);
        b3 = b2; b4 = b1;
        printf("%d %d %d %d\n", a3, b3, a4, b4);
    }
    else if (a1 != a2 && b1 == b2)
    {
        b3 = b4 = b1 + abs(a1 - a2);
        a3 = a1; a4 = a2;
        printf("%d %d %d %d\n", a3, b3, a4, b4);
    }
    else if (a1 == a2 && b1 == b2)
        puts("-1");
    else if (abs(a1 - a2) == abs(b1 - b2))
    {
        a3 = a2; b3 = b1;
        a4 = a1; b4 = b2;
        printf("%d %d %d %d\n", a3, b3, a4, b4);
    }
    else puts("-1");
}

int main()
{
    while (cin >> a1 >> b1 >> a2 >> b2)
    solve();
    return 0;
}