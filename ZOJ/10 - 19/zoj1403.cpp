// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   ZOJ 1403                                                 *
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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

string str, ans;
int sum;

bool calc(int a, int b, int c, int d, int e)
{
	long long tmp = 0;
	#define toDEC(x) ((x) - 'A' + 1)
	tmp += toDEC(str[a]);
	tmp -= std::pow(toDEC(str[b]), 2);
	tmp += std::pow(toDEC(str[c]), 3);
	tmp -= std::pow(toDEC(str[d]), 4);
	tmp += std::pow(toDEC(str[e]), 5);
	#undef toDEC
	return tmp == sum;
}
bool check()
{
	int sz = str.size();
	ans = "01234";
	sort(str.rbegin(), str.rend());
	for (int i1 = 0; i1 < sz; i1++)
	{
		for (int i2 = 0; i2 < sz; i2++)
		{
			if (i2 == i1)
				continue;
			for (int i3 = 0; i3 < sz; i3++)
			{
				if (i3 == i2 || i3 == i1)
					continue;
				for (int i4 = 0; i4 < sz; i4++)
				{
					if (i4 == i3 || i4 == i2 || i4 == i1)
						continue;
					for (int i5 = 0; i5 < sz; i5++)
					{
						if (i5 == i4 || i5 == i3 || i5 == i2 || i5 == i1)
							continue;
                        ans[0] = str[i1];
						ans[1] = str[i2];
						ans[2] = str[i3];
						ans[3] = str[i4];
						ans[4] = str[i5];
						if (calc(i1, i2, i3, i4, i5) == 1)
							return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	while (~scanf("%d", &sum))
	{
		if (sum == 0) break;
		str = nextStr();
		if (!check()) puts("no solution");
		else puts(ans.c_str());
	}
	return 0;
}
