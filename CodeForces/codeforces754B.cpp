// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #390 Div.2 B                                             *
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

int dx1[] = {  1,  1,  0, -1, -1 ,-1,  0,  1,  1,  1,  0, -1 };
int dy1[] = {  0, -1, -1, -1,  0,  1,  1,  1,  0, -1, -1, -1 };
int dx2[] = {  2,  2,  0, -2, -2 ,-2,  0,  2, -1, -1,  0,  1 };
int dy2[] = {  0, -2, -2, -2,  0,  2,  2,  2,  0,  1,  1,  1 };

inline bool inbound(int x, int l = 0, int r = 5)
{
	return x >= l && x < r;
}

inline bool ongrid(int x, int y)
{
	return inbound(x) && inbound(y);
}

char grid[5][5];

int main()
{
	const int n = 4;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	bool flag = false;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		if (grid[i][j] != '.') continue;
		for (int d = 0; d < 12; d++)
		{
			if ( !ongrid( i + dx1[d], j + dy1[d] ) ) continue;
			if ( !ongrid( i + dx2[d], j + dy2[d] ) ) continue;
			char ch1 = grid[i + dx1[d]][j + dy1[d]];
			char ch2 = grid[i + dx2[d]][j + dy2[d]];
			if (ch1 == 'x' && ch2 == 'x') { flag = 'true'; break; }
		}
	}
	puts( flag ? "YES" : "NO" );
	return 0;
}