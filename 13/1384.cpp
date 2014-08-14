// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1384                                             *
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

const int MaxN = 10005;
const int MaxM = 10005;
const int inf  = 1e9;

struct node { int u, v, b, c; node(){ u = v = b = c = 0; } };
struct edg  { int u, v, cost; edg(){ u = v = cost = 0; } };
node data[MaxN];
edg  E[MaxM], ZERO;
int In[MaxN], ID[MaxN], vis[MaxN], pre[MaxN];
int NV, NE, Minroot, cnte;
int t, tt, n, m, c;

void init()
{
    cnte = 0;
    fill(E, E + MaxM, ZERO);
}

void add_edge(const int& u, const int& v, const int& w)
{
    E[cnte].u = u; E[cnte].v = v;
    E[cnte++].cost = w;
}

int Directed_MST(int root)
{
    int ret = 0;
    int i, u, v;
    while(true) {
        for (int i = 0; i < NV; i++) In[i] = inf;
        for (int i = 0; i < NE; i++)
		{// 找最小入边
            u = E[i].u;
            v = E[i].v;
            if (E[i].cost < In[v] && u != v)
			{
                In[v] = E[i].cost;
				if (u == root) // 不能直接等于v，因为会缩边
                    Minroot = i;
                pre[v] = u;
            }
        }
        for (int i = 0; i < NV; i++)
		{// 如果存在除root以外的孤立点，则不存在最小树形图
            if (i == root) continue;
            if (In[i] == inf) return -1;
        }

        int cnt = 0;
		fill(ID, ID + MaxN, -1);
		fill(vis, vis + MaxN, -1);
        In[root] = 0;

        for (int i = 0; i < NV; i++)
		{// 找环
            ret += In[i];
            int v = i;
            while (vis[v] != i && ID[v] == -1 && v != root)
			{
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && ID[v] == -1)
			{// 缩点并且重新标号
                for (u = pre[v]; u != v; u = pre[u]) ID[u] = cnt;
                ID[v] = cnt++;
            }
        }
        if (cnt == 0) break;
        for (int i = 0; i < NV; i++) // 重新标号
            if (ID[i] == -1) ID[i] = cnt++;
        for (int i = 0; i < NE; i++)
		{// 更新其他点到环的距离
            v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if (E[i].u != E[i].v) E[i].cost -= In[v];
        }
        NV = cnt;
        root = ID[root];
    }
    return ret;
}



inline bool test(int x)
{
    init();
    int cnt = 0;
    for (int i = 0; i < m; i++) if (data[i].b >= x)
        add_edge(data[i].u, data[i].v, data[i].c), cnt++;
    NV = n; NE = m;
    int tmp = Directed_MST(0);
    if (tmp == -1) return false;
    else if (tmp > c) return false;
    else return true;

}

int Bsearch(int l, int r)
{
    int ans = 0;
    while (r >= l)
    {
        int mid = (r + l) / 2;
        if (test(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return r;
}

void solve()
{
    init();
    int l = 0, r = 0;
    n = nextInt(); m = nextInt(); c = nextInt();
    for (int i = 0; i < m; i++)
    {
        data[i].u = nextInt(); data[i].v = nextInt();
        data[i].b = nextInt(); data[i].c = nextInt();
        updateMax(r, data[i].b);
    }
    if (!test(0))
        printf("Case %d: impossible\n", ++tt);
    else
    {
        int ans = Bsearch(l, r);
        printf("Case %d: %d kbps\n", ++tt, ans);
    }
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
