// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   D                                                        *
*****************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }

const int MaxN = 32768;
int tree[MaxN + 1];
int n, tmp, ans[MaxN >> 1];

inline int lowbit(int x) { return x & (-x); }

inline void add(int x, int v)
{
	for (int i = x; i <= MaxN; i += lowbit(i)) tree[i] += v;
}

inline int get(int x)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i)) sum += tree[i];
	return sum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
	{
        scanf("%d%*d", &tmp); tmp++;
        add(tmp, 1); ans[get(tmp) - 1]++;
	}
	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	return 0;
}
