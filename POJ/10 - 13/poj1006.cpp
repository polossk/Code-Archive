// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   E                                                        *
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
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }
bool visit[1000005];
int p, e, i, d, tt;
int main()
{
	while(cin >> p >> e >> i >> d)
	{
		if ((p == -1) && (e == -1) && (i == -1) && (d == -1)) break;
		int lcm=21252;
		int n = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
		if (n == 0) n = 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++tt, n);
	}
	return 0;
}