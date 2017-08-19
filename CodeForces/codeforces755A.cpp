// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   8VC Venture Cup 2017 - Elimination Round A               *
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

int main()
{
	int n = nextInt();
	if (n == 1) { cout << "3" << endl; return 0; }
	if (n % 2 == 1) { cout << "1" << endl; return 0; }
	for (int m = 1; m <= 1000; m++)
	{
		int p = n * m + 1;
		bool flag = true;
		for (int i = 3; i * i <= p; i += 2)
		{
			if (p % i == 0) { flag = false; break; }
		}
		if (!flag) { cout << m << endl; return 0; }
	}
	return 0;
}