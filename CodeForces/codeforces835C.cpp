// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #427 (Div. 2) C                         *
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

vector<int> grid[105][105];
int tmp[105][105];
int sum[105][105][11];

inline int brightness(int s, int t, int c)
{
	if (s < 0) return 0;
	return (s + t) % (c + 1);
}

int main()
{
	int n = nextInt();
	int q = nextInt();
	int c = nextInt();
	while (n--)
	{
		int x = nextInt();
		int y = nextInt();
		grid[x][y].push_back(nextInt());
	}

	for (int t = 0; t < 11; t++)
	{
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
		{
			tmp[i][j] = tmp[i][j - 1];
			if (grid[i][j].empty()) continue;
			for (auto e : grid[i][j])
			{
				tmp[i][j] += brightness(e, t, c);
			}
		}
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
		{
			sum[i][j][t] = sum[i - 1][j][t] + tmp[i][j];
		}
	}

	while (q--)
	{
		int t = nextInt() % (c + 1);
		int x1 = nextInt();
		int y1 = nextInt();
		int x2 = nextInt();
		int y2 = nextInt();
		int ans = sum[x2][y2][t] + sum[x1 - 1][y1 - 1][t] - sum[x1 - 1][y2][t] - sum[x2][y1 - 1][t];
		cout << ans << endl;
	}
	return 0;
}