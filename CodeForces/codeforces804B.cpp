// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #410 (Div. 2) D                         *
*****************************************************************************/

#include <bits/stdc++.h>
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

const int MOD = 1000000000 + 7;
const int MAXL = 1000000 + 5;
char str[MAXL];

int64 mul_mod(int64 a, int64 b, int64 m = MOD)
{
	int64 t = 0; a %= m; b %= m;
	while (b)
	{
		if (b & 1) t += a, t %= m;
		a <<= 1; a %= m; b >>= 1;
	}
	return t;
}
int64 pow_mod(int64 a, int64 b, int64 m = MOD)
{
	int64 ans = 1; a %= m;
	while (b)
	{
		if (b & 1) { ans = (ans * a) % m; b--; }
		b >>= 1; a = (a * a) % m;
	}
	return ans;
}

int main()
{
	int64 ans = 0LL, len = 0LL;
	scanf(" %s", str);
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != 'a')
		{
			ans = (ans + pow_mod(2LL, len) - 1) % MOD;
		}
		else len++;
	}
	cout << ans << endl;
	return 0;
}