#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
// inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MAXN = 10000 + 10;

vector<int> g[MAXN];
int low[MAXN], dfn[MAXN];
int dfs_cnt, scc_cnt, sccno[MAXN];
vector<int> scc[MAXN];
bool used[MAXN];
int n, m;

void init()
{
    dfs_cnt = scc_cnt = 0;
    memset(low, 0, sizeof low);
    memset(dfn, 0, sizeof dfn);
    memset(sccno, 0, sizeof sccno);
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i++) g[i].clear();
}

stack<int> s;
void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++dfs_cnt;
    s.push(u); used[u] = true;
    for (int i = 0, sz = g[u].size(); i < sz; i++)
    {
        int v = g[u][i];
        if (!dfn[v])
        {
            tarjan(v, u);
            updateMin(low[u], low[v]);
        }
        else if (used[v])
        {
            updateMin(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        scc[++scc_cnt].clear();
        while (true)
        {
            int v = s.top(); s.pop();
            used[v] = false;
            sccno[v] = scc_cnt;
            scc[scc_cnt].push_back(v);
            if (v == u) break;
        }
    }
}

void solve()
{
    n = nextInt(); m = nextInt();
    init();
    for (int i = 0; i < m; i++)
    {
        int _ = nextInt();
        g[_].push_back(nextInt());
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, -1);
    vector<int> in(scc_cnt + 1, 0), out(scc_cnt + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0, sz = g[i].size(); j < sz; j++)
        {
            int u = sccno[i], v = sccno[g[i][j]];
            if (u != v) { out[u]++; in[v]++; }
        }
    }
    if (scc_cnt == 1) { puts("0"); return; }
    auto f = [](int _, int _2) -> int { return _ + (_2 == 0); };
    int a = std::accumulate(in.begin() + 1, in.end(), 0, f);
    int b = std::accumulate(out.begin() + 1, out.end(), 0, f);
    printf("%d\n", max(a, b));
}

int main()
{
    int _ = nextInt();
    while (_--) solve();
    return 0;
}
