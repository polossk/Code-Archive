// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #394 (Div. 2) D                         *
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

int n, l, r;
vector<int64> a, b, c, p;

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) a.push_back(nextInt());
    for (int i = 0; i < n; i++) p.push_back(nextInt());
    for (int i = 0; i < n; i++) b.push_back(a[i] + p[i]);
    int b_min = *min_element(b.begin(), b.end());
    int err = b_min - l;
    for (auto& e : b) e -= err;
    int b_max = *max_element(b.begin(), b.end());
    if (b_max > r) { puts("-1"); return 0; }
    for (int i = 0; i < n; i++)
    {
        if (i == 0) cout << b[i];
        else cout << " " << b[i];
    }
    cout << endl;
    return 0;
}