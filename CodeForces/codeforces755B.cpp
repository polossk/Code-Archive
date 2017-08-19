// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   8VC Venture Cup 2017 - Elimination Round B               *
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

set<string> player1;

int main()
{
	int a = nextInt();
	int b = nextInt();
	for (int i = 0; i < a; i++)
		player1.insert(nextStr());
	int common = 0;
	for (int i = 0; i < b; i++)
	{
		auto result = player1.find(nextStr());
		if (result != player1.end()) common++;
	}
	int pa = a - common, pb = b - common;
	if (pa == pb)
		puts(common % 2 ? "YES" : "NO");
	else puts(pa > pb ? "YES" : "NO");
	return 0;
}