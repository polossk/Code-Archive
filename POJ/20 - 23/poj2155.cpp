// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   C                                                        *
*****************************************************************************/

#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline string nextStr() { string s; cin >> s; return s; }
inline char   nextChr() { char   c; scanf(" %c", &c); return c; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MaxN = 1024;
int mat[MaxN][MaxN];
int t, a, b, c, d;
int n, m; char op;
bool isFirst = 1;

inline int lowbit(int x) { return x & (-x); }

inline void init() { memset(mat, 0, sizeof(mat)); }

void add(int x, int y, int v)
{
	for (int i = x; i > 0; i -= lowbit(i))
	for (int j = y; j > 0; j -= lowbit(j))
		mat[i][j] += v;
}

int query(int x, int y)
{
	int ans = 0;
	for (int i = x; i < MaxN; i += lowbit(i))
	for (int j = y; j < MaxN; j += lowbit(j))
		ans += mat[i][j];
	return ans;
}

void solve()
{
	init();
	if (isFirst) isFirst = 0;
	else puts("");
	n = nextInt(); m = nextInt();
	while (m--)
	{
		op = nextChr();
		if (op == 'Q')
		{
			a = nextInt(); b = nextInt();
			printf("%d\n", query(a, b) & 1);
		}
		else
		{
			a = nextInt(); b = nextInt();
			c = nextInt(); d = nextInt();
			add(c, d, 1); add(a - 1, b - 1, 1);
			add(c, b - 1, -1); add(a - 1, d, -1);
		}
	}
}

int main()
{
	t = nextInt(); while (t--) solve();
}
