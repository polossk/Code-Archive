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
const int MAXM = 100000 + 10;

struct Edge {
    int nxt, to, val;
} edge[MAXM];

int head[MAXN], tot;
int dp[MAXN], in[MAXN], out[MAXN], que[MAXN];
bool vis[MAXN];

int n, m;

void init()
{
    tot = 0;
    memset(dp, 0, sizeof dp);
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    memset(head, -1, sizeof head);
    memset(vis, false, sizeof vis);
}

inline void addedge(int u, int v, int w)
{
    edge[tot].nxt = head[u];
    edge[tot].to = v;
    edge[tot].val = w;
    head[u] = tot++;
}

void topsort()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i]) que[res++] = i;
    }
    for (int i = 0; i < res; i++)
    {
        for (int j = head[que[i]]; ~j; j = edge[j].nxt)
        {
            int to = edge[j].to;
            updateMax(dp[to], dp[que[i]] + edge[j].val);
            in[to]--;
            if (!in[to]) que[res++] = to;
        }
    }
}

void solve()
{
    init();
    n = nextInt(); m = nextInt();
    for (int i = 0; i < m; i++)
    {
        int u = nextInt();
        int v = nextInt();
        in[v]++; out[u]++;
        addedge(u, v, nextInt());
    }
    topsort();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!out[i]) updateMax(ans, dp[i]);
    }
    printf("%d\n", ans);
}

int main()
{
    int _ = nextInt();
    while (_--) solve();
    return 0;
}
