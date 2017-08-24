// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #410 (Div. 2) C                         *
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

inline bool odd(int64 n) { return n & 1; }

inline int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
	int n = nextInt();
	vector<int64> a;
	for (int i = 0; i < n; i++) a.push_back(nextI64());
	
	int64 g = a[0]; bool flag = true;
	for (int i = 0; i < n; i++)
	{
		g = gcd(g, a[i]);
		if (g == 1) { flag = false; break; }
	}
	if (flag) { puts("YES\n0"); return 0; }

	int ans = 0;

	for (int i = 0; i + 1 < n; i++)
	{
		if (odd(a[i]) && odd(a[i + 1]))
		{
			ans++;
			int64 _1 = a[i] - a[i + 1];
			int64 _2 = a[i] + a[i + 1];
			a[i] = _1; a[i + 1] = _2;
		}
	}

	for (int i = 0; i + 1 < n; i++)
	{
		if (odd(a[i + 1]) ^ odd(a[i]))
		{
			ans += 2;
			int64 _1 = a[i] - a[i + 1];
			int64 _2 = a[i] + a[i + 1];
			a[i] = _1 - _2; a[i + 1] = _1 + _2;
		}
	}
	puts("YES");
	cout << ans << endl;
	return 0;
}