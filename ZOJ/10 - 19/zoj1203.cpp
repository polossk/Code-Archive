// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   D                                                        *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

const int MaxN = 128;
const int MaxM = 8196 * 2;
int fa[MaxN], rk[MaxN];

inline void init(int n) { fill(rk, rk + n, 0); for (int i = 0; i <= n; i++) fa[i] = i; }

inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }

inline bool Query(int x, int y) { return _find(x) == _find(y); }

bool Merge(int x, int y)
{
    x = _find(x); y = _find(y);
    if (x == y) return 0;
    if (rk[x] < rk[y]) fa[x] = y;
    else { fa[y] = x; rk[x] += (rk[x] == rk[y]); }
    return 1;
}

int tt;

struct Edge
{
    int u, v; double w;
    inline bool operator<(const Edge& b) const { return w < b.w; }
};
typedef pair<double, double> pnt;
pnt data[MaxN];
Edge edges[MaxM];
int n, m;
double ans;

void Kruskal()
{
    int cnt = 0;
    for (int i = 0; i < m && cnt < n - 1; i++)
    {
        int a = _find(edges[i].u);
        int b = _find(edges[i].v);
        if (a == b) continue;
        ans += edges[i].w;
        Merge(edges[i].u, edges[i].v);
        cnt++;
    }
}


inline double calc(int i, int j)
{
    double dx = data[i].first - data[j].first;
    double dy = data[i].second - data[j].second;
    double ds = dx * dx + dy * dy;
    return sqrt(ds);
}


void solve()
{
    ans = 0; m = 0; init(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &data[i].first, &data[i].second);
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
    {
        edges[m].u = i;
        edges[m].v = j;
        edges[m++].w = calc(i, j);
    }
    sort(edges, edges + m);
    Kruskal();
    if (tt) puts("");
    printf("Case #%d:\n", ++tt);
    printf("The minimal distance is: %.2lf\n", ans);
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}