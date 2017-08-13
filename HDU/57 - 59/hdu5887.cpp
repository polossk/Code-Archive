// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 5887                                                 *
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

typedef long double real80;

const int MAXN = 105;
const real80 EPS = 0.4; // round

int n;
int64 ans, limit;
// first -> v, second -> w
vector< pair<int64, int64> > herb;
#define ww second
#define vv first

inline bool judge(int i, int64 w, int64 v)
{
    real80 pv = real80(1.0) * herb[i].vv / herb[i].ww;
    return int64(v + pv * (limit - w) + EPS) <= ans;
}

void dfs(int i, int64 w, int64 v)
{
    updateMax(ans, v);
    if (i == n) return;
    if (judge(i, w, v)) return;
    if (w + herb[i].ww <= limit)
    {
        dfs(i + 1, w + herb[i].ww, v + herb[i].vv);
    }
    dfs(i + 1, w, v);
}

void solve()
{
    herb.clear();
    ans = 0;
    for (int i = 0; i < n; i++)
        herb.push_back(make_pair(next64d(), next64d()));
    sort(herb.begin(), herb.end(),
        [](const pair<int64, int64>& a, const pair<int64, int64>& b) -> bool
        {
            return a.vv * b.ww > a.ww * b.vv;
        });
    dfs(0, 0, 0);
    printf("%I64d\n", ans);
}

#undef ww
#undef vv

int main()
{
    while (~scanf("%d%I64d", &n, &limit)) solve();
    return 0;
}
// g++ C.cpp -o C.exe -std=c++11