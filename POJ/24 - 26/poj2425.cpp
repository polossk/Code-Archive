// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2425                                                 *
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
const int MaxE = 1000005;

int head[MaxN], tot;
int next[MaxE], path[MaxE];
int n, sg[MaxN];
inline void addEdge(int x, int y)
{
	path[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
}

int dfs(int x)
{
	if (~sg[x]) return sg[x];
	bool vis[MaxN]; fill(vis, vis + MaxN, 0);
	for (int i = head[x]; i; i = next[i])
		vis[dfs(path[i])] = 1;
	for (int i = 0; ; i++) if (!vis[i])
		return sg[x] = i;
}

void solve()
{
	tot = 0;
	memset(head, 0, sizeof(head));
	memset(sg, -1, sizeof(sg));
	for (int i = 0; i < n; i++)
	{
		int x = nextInt();
		for (int j = 0; j < x; j++)
			addEdge(i, nextInt());
	}
	while (int q = nextInt())
	{
		int ans = 0;
		for (int i = 0; i < q; i++)
			ans ^= dfs(nextInt());
		if (ans) puts("WIN");
		else puts("LOSE");
	}
}

int main()
{
	while (~scanf("%d", &n)) solve();
    return 0;
}
