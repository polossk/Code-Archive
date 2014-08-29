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
    int x, y;
    inline bool operator<(const pnt& b) const
    {
        if (x == b.x) return y < b.y;
        else return x < b.x;
    }
};

const int MaxN = 1024;
int tree[MaxN];
pnt data[MaxN * MaxN];
int t, tt;
int n, m, k;

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
    n = nextInt(); m = nextInt(); k = nextInt();
    for (int i = 1; i <= k; i++)
    {
        data[i].x = nextInt();
        data[i].y = nextInt();
    }
    sort(data + 1, data + k + 1);
    fill(tree, tree + MaxN, 0);
    int64 ans = 0;
    for (int i = 1; i <= k; i++)
    {
        add(data[i].y, 1);
        ans += i - get(data[i].y);
    }
    printf("Test case %d: %I64d\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
