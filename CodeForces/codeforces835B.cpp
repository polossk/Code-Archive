// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #427 (Div. 2) B                         *
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

int sumOfDights(string s)
{
	return std::accumulate(s.begin(), s.end(), 0, [](int _, char ch) -> int
	{
		return _ + ch - '0';
	});
}

int main()
{
	int k = nextInt();
	string s = nextStr();
	int q = sumOfDights(s);
	if (q >= k) { puts("0"); return 0; }
	int ans = 0, todo = k - q;
	vector<int> a(10, 0);
	for (auto ch : s) a[ch - '0']++;
	for (int i = 0; i < 9; i++)
	{
		while (a[i])
		{
			if (todo <= 0) break;
			todo -= 9 - i;
			ans++; a[i]--;
		}
	}
	printf("%d\n", ans);
	return 0;
}