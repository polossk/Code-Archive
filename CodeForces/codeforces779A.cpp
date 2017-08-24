// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #402 (Div. 2) A                         *
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

vector<int> a, b, c;

int main()
{
    int n = nextInt();
    a.resize(5); b.resize(5); c.resize(5);
    for (int i = 0; i < 5; i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) a[nextInt() - 1]++;
    for (int i = 0; i < n; i++) b[nextInt() - 1]++;
    for (int i = 0 ; i < 5; i++)
    {
        c[i] = a[i] + b[i];
        if (c[i] & 1) { puts("-1"); return 0; }
        c[i] >>= 1;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans += abs(a[i] - c[i]);
    }
    cout << (ans / 2) << endl;
    return 0;
}