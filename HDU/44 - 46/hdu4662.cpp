// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4662                                                 *
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

int tt;

void solve()
{
    int m = 0, u = 0, i = 0;
    string s = nextStr();
    for (auto ch : s)
    {
        m += ch == 'M';
        u += ch == 'U';
        i += ch == 'I';
    }
    if (m == 1 && s[0] == 'M')
    {
        i += u * 3;
        bool hoge = i == 1;
        bool piyo = (i % 2 == 0) && (i % 3 != 0);
        if (hoge || piyo) { puts("Yes"); return; }
    }
    puts("No");
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
// g++ J.cpp -o J.exe -std=c++11
// 2
// MI
// MU