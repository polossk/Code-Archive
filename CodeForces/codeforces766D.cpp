// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #396 (Div. 2) D                         *
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

const int MAXN = 202020;

inline int _L(int _) { return _ << 1; }
inline int _R(int _) { return 1 + _L(_); }

int p[MAXN];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }
int u(int x, int y) { p[f(x)] = f(y); }

inline int fL(int _) { return f(_L(_)); }
inline int fR(int _) { return f(_R(_)); }

map<string, int> mp;

int main()
{
	int n = nextInt();
	int m = nextInt();
	int q = nextInt();
	for (int i = 0; i < n * 2; i++) p[i] = i;
	for (int i = 0; i < n; i++) mp[nextStr()] = i;
	while (m--)
	{
		int hoge = nextInt();
		int x = mp[nextStr()];
		int y = mp[nextStr()];
		if (hoge == 1)
		{
			if (fL(x) == fR(y) || fR(x) == fL(y)) puts("NO");
			else
			{
				puts("YES");
				u(_L(x), _L(y));
				u(_R(x), _R(y));
			}
		}
		else
		{
			if (fL(x) == fL(y) || fR(x) == fR(y)) puts("NO");
			else
			{
				puts("YES");
				u(_L(x), _R(y));
				u(_R(x), _L(y));
			}
		}
	}
	while (q--)
	{
		int x = mp[nextStr()];
		int y = mp[nextStr()];
		if (fL(x) == fL(y) && fR(x) == fR(y))
			puts("1");
		else
		{
			if (fL(x) == fR(y) && fR(x) == fL(y))
				puts("2");
			else puts("3");
		}
	}
	return 0;
}