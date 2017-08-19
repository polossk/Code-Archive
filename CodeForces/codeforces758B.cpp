// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #392 (Div. 2) B                         *
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

int sum[4];
char cc[4];
char ch[] = "RBYG";
int main()
{
	string s = nextStr();
	for (int i = 0, j = 0; s[i]; i++, j++, j %= 4)
	{
		if (s[i] != '!') cc[j] = s[i];
		else sum[j]++;
	}
	for (int j = 0; j < 4; j++)
		for (int i = 0; i < 4; i++)
			if (cc[i] == ch[j])
			{
				if (j == 0)
					printf("%d",sum[i]);
				else printf(" %d",sum[i]);
			}
	return 0;
}