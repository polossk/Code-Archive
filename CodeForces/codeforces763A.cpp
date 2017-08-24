// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #395 (Div. 2) C                         *
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

const int MAXN = 200005;

int head[MAXN], cnt, n;
int dfn[MAXN], color[MAXN], hoge;
set<int> st;

struct edge {
    int n, t; edge(int _1 = 0, int _2 = 0) : n(_1), t(_2) {}
} edges[MAXN << 1];

void addedge(int u, int v)
{
    edges[cnt] = edge(head[u], v);
    head[u] = cnt++;
    edges[cnt] = edge(head[v], u);
    head[v] = cnt++;
}

void dfs(int u, int cr)
{
    dfn[u] = hoge;
    for (int i = head[u]; i != -1; i = edges[i].n)
    {
        int v = edges[i].t;
        if(!dfn[v] && color[v] == cr)
            dfs(v, cr);
    }
}

bool check(int u)
{
    st.clear();
    for(int i = head[u]; i != -1; i = edges[i].n)
    {
        int v = edges[i].t;
        st.insert(dfn[v]);
    }
    st.insert(dfn[u]);
    return st.size() == hoge;
}

bool solve()
{
    for (int i = 1; i <= n; i++)
        if (check(i))
    {
        cout << "YES" << endl << i << endl;
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++) addedge(nextInt(), nextInt());
    for (int i = 1; i <= n; i++) color[i] = nextInt();
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            hoge++;
            dfs(i, color[i]);
        }
    }
    if (!solve()) puts("NO");
    return 0;
}