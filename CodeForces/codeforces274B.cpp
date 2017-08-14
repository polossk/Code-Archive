// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 274B                                          *
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

const int MAXN = 100000 + 5;

int64 up[MAXN], down[MAXN], a[MAXN];
vector<int> e[MAXN];

void addedge(int u, int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}

void dfs(int u, int p)
{
    up[u] = down[u] - 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == p) continue;
        dfs(v, u);
        updateMax(up[u], up[v]);
        updateMax(down[u], down[v]);
    }
    a[u] += up[u] - down[u];
    if (a[u] > 0) down[u] += a[u];
    else up[u] -= a[u];
}

void solve()
{
    int n = nextInt();
    for (int i = 0; i < MAXN; i++)
        e[i].clear();
    for (int i = 1; i < n; i++)
        addedge(nextInt(), nextInt());
    for (int i = 1; i <= n; i++)
        a[i] = next64d();
    dfs(1, -1);
    cout << up[1] + down[1] << endl;
}

int main()
{
    solve();
    return 0;
}
// g++ F.cpp -o F.exe -std=c++11