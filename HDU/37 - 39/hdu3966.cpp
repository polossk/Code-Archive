// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 3966                                                 *
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

const int MAXN = 50000 + 5;

int n, m, q, tim;

int num[MAXN], siz[MAXN], top[MAXN], son[MAXN];
int dep[MAXN], tid[MAXN], rnk[MAXN], fa[MAXN];
int head[MAXN], to[MAXN << 1], next_[MAXN << 1], edge;

// siz[] 用来保存以x为根的子树节点个数
// top[] 用来保存当前节点的所在链的顶端节点
// son[] 用来保存重儿子
// dep[] 用来保存当前节点的深度
// fa[] 用来保存当前节点的父亲
// tid[] 用来保存树中每个节点剖分后的新编号
// rnk[] 用来保存当前节点在线段树中的位置

void init()
{
    memset(head, -1, sizeof head);
    memset(son, -1, sizeof son);
    tim = edge = 0;
}

void addedge(int u, int v)
{
    to[edge] = v; next_[edge] = head[u]; head[u] = edge++;
    to[edge] = u; next_[edge] = head[v]; head[v] = edge++;
}

// 树链剖分: 记录所有重边
void dfs1(int u, int father, int depth)
{
    dep[u] = depth;
    fa[u] = father;
    siz[u] = 1;
    for (int i = head[u]; ~i; i = next_[i])
    {
        int v = to[i];
        if (v != father)
        {
            dfs1(v, u, depth + 1);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
}

// 树链剖分: 连接重边变成重链
void dfs2(int u, int tp)
{
    top[u] = tp;
    tid[u] = ++tim;
    rnk[tid[u]] = u;
    if (son[u] == -1) return;
    dfs2(son[u], tp);
    for (int i = head[u]; ~i; i = next_[i])
    {
        int v = to[i];
        if (v != son[u] && v != fa[u])
            dfs2(v, v);

    }
}

struct node { int sum, col; } Tree[MAXN << 2];

inline void pushUp(int root)
{
    int next = root << 1;
    Tree[root].sum = max(Tree[next].sum, Tree[next | 1].sum);
}

void pushDown(int root, int m)
{
    if (Tree[root].col)
    {
        int next = root << 1;
        Tree[next].col += Tree[root].col;
        Tree[next | 1].col += Tree[root].col;
        Tree[next].sum += (m - (m >> 1)) * Tree[root].col;
        Tree[next | 1].sum += (m >> 1) * Tree[root].col;
        Tree[root].col = 0;
    }
}

void build(int l, int r, int root)
{
    // Tree[root].l = l; Tree[root].r = r;
    Tree[root].col = 0;
    if (l == r) { Tree[root].sum = num[rnk[l]]; return; }
    int mid = (l + r) >> 1, next = root << 1;
    build(l, mid, next); build(mid + 1, r, next | 1);
    pushUp(root);
}

void update(int XL, int XR, int v, int l, int r, int root)
{
    if (XL <= l && XR >= r)
    {
        Tree[root].col += v;
        Tree[root].sum += v * (r - l + 1);
        return;
    }
    pushDown(root, r - l + 1);
    int mid = (l + r) >> 1, next = root << 1; 
    if (XL <= mid) update(XL, XR, v, l, mid, next);
    if (XR > mid) update(XL, XR, v, mid + 1, r, next | 1);
    pushUp(root);
}

int query(int x, int l, int r, int root)
{
    if (l == r) return Tree[root].sum;
    pushDown(root, r - l + 1);
    int mid = (l + r) >> 1, next = root << 1;
    int ret = (x <= mid) ? query(x, l, mid, next)
        : query(x, mid + 1, r, next | 1);
    pushUp(root);
    return ret;
}

void modify(int x, int y, int val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(tid[top[x]], tid[x], val, 1, n, 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(tid[x], tid[y], val, 1, n, 1);
}

char cmd[5];

void solve()
{
    init();
    for (int i = 1; i <= n; i++) num[i] = nextInt();
    for (int i = 1; i <= m; i++) addedge(nextInt(), nextInt());
    dfs1(1, 0, 0); dfs2(1, 1); build(1, n, 1);
    while (q--)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'Q')
            printf("%d\n", query(tid[nextInt()], 1, n, 1));
        else
        {
            int a = nextInt();
            int b = nextInt();
            int c = nextInt();
            modify(a, b, cmd[0] == 'D' ? -c : c);
        }
    }
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &q)) solve();
    return 0;
}