// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2599                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
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
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

const int MaxN = 1024;
bool g[MaxN][MaxN];
int n, k, res;
bool vis[MaxN];

bool dfs(int m)
{
	for (int i = 1; i <= n; i++)
		if (g[m][i] && !vis[i])
	{
		vis[m] = true;
		if (!dfs(i))
		{
			vis[m] = false;
			res = i;
			return true;
		}
		vis[m] = false;
	}
	return false;
}

void solve()
{
	memset(g, 0, sizeof(g));
	for (int i = 1; i < n; i++)
	{
		int x = nextInt();
		int y = nextInt();
		g[x][y] = g[y][x] = 1;
	}
	memset(vis, 0, sizeof(vis));
	bool ans = dfs(k);
	if (ans)
		printf("First player wins flying to airport %d\n", res);
	else puts("First player loses");
}

int main()
{
	while (~scanf("%d%d", &n, &k)) solve();
    return 0;
}
