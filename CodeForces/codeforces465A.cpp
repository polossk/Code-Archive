// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #265 Div.2 A                                             *
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
const int MaxN = 105;
int n, s1[MaxN], s2[MaxN];

void solve()
{
    for (int i = 0; i < n; i++)
        s2[i] = nextChr() - '0';
    for (int i = 0; i < n; i++)
        s1[i] = s2[i];
    bool tmp = 1;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 1 && tmp == 1) s2[i] = 0;
        else if (s1[i] == 0 && tmp == 1) { tmp = 0; s2[i] = 1; }
        else continue;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (s1[i] != s2[i])? 1: 0;
    cout << ans << endl;
}

int main()
{
    n = nextInt();
    solve();
    return 0;
}