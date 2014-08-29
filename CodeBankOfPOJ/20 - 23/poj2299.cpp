// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   G                                                        *
*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

struct pnt
{
    int v, p;
    inline bool operator<(const pnt& b) const { return v < b.v; }
};

const int MaxN = 524288;
int b[MaxN], tree[MaxN];
pnt data[MaxN];
int n;

inline int lowbit(int x) { return x & (-x); }

inline void add(int x, int v)
{
	for (int i = x; i < MaxN; i += lowbit(i)) tree[i] += v;
}

int64 get(int x)
{
    int64 sum = 0;
	for (int i = x; i > 0; i -= lowbit(i)) sum += tree[i];
	return sum;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        data[i].v = nextInt();
        data[i].p = i;
    }
    sort(data + 1, data + n + 1);
    for (int i = 1; i <= n; i++) b[data[i].p] = i;
    fill(tree, tree + MaxN, 0);
    int64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(b[i], 1);
        ans += i - get(b[i]);
    }
    cout << ans << endl;
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}
