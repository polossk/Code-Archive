// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
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
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

int64 mul_mod(int64 a, int64 b, int64 m)
{
	int64 t = 0; a %= m; b %= m;
	while (b)
    {
		if (b & 1) t += a, t %= m;
		a <<= 1; a %= m;
		b >>= 1;
	}
	return t;
}

int64 pow_mod(int64 a, int64 b, int64 m)
{
	int64 ans = 1; a %= m;
	while (b)
	{
		if (b & 1) { ans = mul_mod(ans, a, m); b--; }
		b /= 2; a = mul_mod(a, a, m);
	}
	return ans;
}

int64 Legendre(int64 d, int64 p)
{
    if (d > 0)
    {
        d %= p;
        if (d == 0) return 0;
        if (pow_mod(d, (p - 1) / 2, p) == 1) return 1;
        else return -1;
    }
    else
    {
        int64 coef = ((p - 1) % 4 == 0)? 1: -1;
        d = -d; d %= p;
        if (pow_mod(d, (p - 1) / 2, p) == 1) return coef;
        else return -coef;
    }
}

int64 a, b;
int t, tt;

void solve()
{
    a = next64d(); b = next64d();
    printf("Scenario #%d:\n", ++tt);
    printf("%d\n\n", ((Legendre(a,b)==-1)?-1:1));
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
