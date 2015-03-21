// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2603 (G++ only)                                      *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
// #pragma comment(linker, "/STACK:1024000000,1024000000")

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

int a[10], num[10005];

void factor(int m)
{
	int now = m, tot = 0;
	for (int i = 2; i <= m / i; i++) if (now % i == 0)
	{
		while (now % i == 0) { ++a[i]; now /= i; }
	}
	if (now != 1) a[now]++;
}

int main()
{
    for (int i = 0; i < 10; i++)
        factor(nextInt());
    int ans = 1;
    for (int i = 1; i < 10005; i++) if (a[i])
        ans = ans * (a[i] + 1) % 10;
    printf("%d\n", ans);
    return 0;
}