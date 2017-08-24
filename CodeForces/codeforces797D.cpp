// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 19 D                        *
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
const int LL = 0, RR = 0x7fffffff;

struct node { int v, fa, l, r; node(){ v = fa = l = r = -1; } };

node tree[MAXN];

set<int> mieta;

inline bool inbound(int x, int l, int r)
{
    return x <= r && l <= x;
}

void dfs(int i, int L, int R)
{
    if (i == -1 || tree[i].v == -1) return;
    if (inbound(tree[i].v, L, R)) mieta.insert(tree[i].v);
    dfs(tree[i].r, max(tree[i].v + 1, L), R);
    dfs(tree[i].l, L, min(tree[i].v - 1, R));
}

int main()
{
    int n = nextInt();
    for (int i = 1; i <= n; i++)
    {
        tree[i].v = nextInt();
        int l = nextInt();
        int r = nextInt();
        tree[i].l = l; tree[i].r = r;
        tree[l].fa = tree[r].fa = i;
    }
    int root = 1;
    for (int i = 1; tree[i].fa != -1; i = tree[i].fa)
        root = tree[i].fa;
    dfs(root, LL, RR);
    int ans = accumulate(tree + 1, tree + n + 1, 0, [](int _, node d){
        if (mieta.count(d.v)) return _;
        else return _ + 1;
    });
    cout << ans << endl;
    return 0;
}