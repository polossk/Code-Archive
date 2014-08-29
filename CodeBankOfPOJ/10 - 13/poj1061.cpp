// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
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

int64 gcd(int64 m, int64 n) { return n == 0? m: gcd(n, m % n); }

int64 gcd_ex(int64 a, int64 b, int64& x, int64& y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    int64 d = gcd_ex(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

int64 x, y, m, n, l;
int64 ar, br;

void solve()
{
    int64 d = gcd_ex(n - m, l, ar, br);
	if ((x - y) % d || m == n) cout << "Impossible" << endl;
	else
	{
		int64 s = l / d;
		ar = ar * ((x - y) / d);
		while (ar < 0) ar += s;
		ar %= s;
		cout << ar << endl;
	}
}

int main()
{
    x = next64d(); y = next64d();
    m = next64d(); n = next64d();
    l = next64d(); solve();
    return 0;
}
