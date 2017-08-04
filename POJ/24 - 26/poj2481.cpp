// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   E                                                        *
*****************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }

struct cow
{
    int x, y, i;
    cow(int a = 0, int b = 0):x(a), y(b), i(0){}
    inline bool operator<(const cow& b) const
    {
        if (y != b.y) return y > b.y;
        else return x < b.x;
    }
    inline bool equalTo(const cow& b) const
    {
        return x == b.x && y == b.y;
    }
};

const int MaxN = 32768 * 4;
int tree[MaxN];
int n, tmp, ans[MaxN];
cow x[MaxN];

inline int lowbit(int x) { return x & (-x); }

inline void add(int x, int v)
{
	for (int i = x; i < MaxN; i += lowbit(i)) tree[i] += v;
}

inline int get(int x)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i)) sum += tree[i];
	return sum;
}

void solve()
{
    fill(tree, tree + MaxN, 0);
    for (int i = 1; i <= n; i++)
	{
        scanf("%d%d", &x[i].x, &x[i].y);
        x[i].i = i;
	}
	sort(x + 1, x + n + 1);
	tmp = 0;
	for (int j = 1; j <= n; j++)
    {
        x[j].equalTo(x[j - 1])? tmp++: tmp = 0;
        ans[x[j].i] = get(x[j].x + 1) - tmp;
        add(x[j].x + 1, 1);
    }
    printf("%d", ans[1]);
	for (int i = 2; i <= n; i++) printf(" %d", ans[i]);
	puts("");
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
	return 0;
}
