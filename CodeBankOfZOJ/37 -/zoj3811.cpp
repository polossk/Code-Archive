// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 3811                                                 *
*****************************************************************************/

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

const int MaxN = 100007;
const char aye[] = "Yes";
const char nay[] = "No";


bool vis[MaxN], isk[MaxN];
vector<int> e[MaxN];
int n, m, k, kn;
int s[MaxN];

void bfs(int x)
{
	queue<int> q; q.push(x);
	while (!q.empty())
	{
		int a = q.front(); q.pop();
		for (int i = 0, sz = e[a].size(); i < sz; i++)
			if (!vis[e[a][i]])
		{
			vis[e[a][i]] = true;
			if (isk[e[a][i]]) continue;
			q.push(e[a][i]);
		}
	}
}

void solve()
{
	memset(isk, 0, sizeof(isk));
	memset(vis, 0, sizeof(vis));
	n = nextInt(); m = nextInt(); k = nextInt();
	for (int i = 0; i < k; i++) nextInt();
	for (int i = 0; i <= n; i++) e[i].clear();
	for (int i = 0; i < m; i++)
	{
		int a = nextInt();
		int b = nextInt();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	kn = nextInt();
	for (int i = 0; i < kn; i++)
	{
		s[i] = nextInt();
		isk[s[i]] = true;
	}
	if (kn != k) { puts(nay); return; }
	vis[s[0]] = true;
	for (int i = 0; i < kn; i++)
	{
		if (!vis[s[i]]) { puts(nay); return; }
		bfs(s[i]);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) { puts(nay); return; }
	puts(aye);
}

int main()
{
	int t = nextInt();
	while (t--) solve();
    return 0;
}
