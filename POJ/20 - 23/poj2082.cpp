// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2082                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

// #include <bits/stdc++.h>
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

int n, tmp;

void solve()
{
	typedef pair<int, int> node;
	stack<node> s;
	int ans = 0, tmp = 0;
	for (int i = 0; i < n; i++)
	{
		int w = nextInt();
		int h = nextInt();
		if (s.empty())
			s.push(make_pair(h, w));
		else
		{
			tmp = 0;
			if (h >= s.top().first)
				s.push(make_pair(h, w));
			else
			{
				while (!s.empty() && s.top().first > h)
				{
					tmp += s.top().second;
					if (ans < tmp * s.top().first)
						ans = tmp * s.top().first;
					s.pop();
				}
				w += tmp;
				s.push(make_pair(h, w));
			}
		}
	}
	tmp = 0;
	while (!s.empty())
	{
		tmp += s.top().second;
		if (ans < tmp * s.top().first)
			ans = tmp * s.top().first;
		s.pop();
	}
	printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d", &n) && n != -1) solve();
	return 0;
}
