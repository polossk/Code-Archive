// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #363 Div.2 C                                             *
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

const int MAXN = 105;
int dp[MAXN][3];

int main()
{
	int n = nextInt();
	vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(nextInt());
	for (int i = 0; i <= n; i++)
		dp[i][0] = dp[i][1] = dp[i][2] = 0x7fff;
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i + 1][0] = 1 + min( min(dp[i][0], dp[i][1]), dp[i][2]);

		if (v[i] == 0) { } // A
		else if (v[i] == 1) // A C
		{
			dp[i + 1][2] = min(dp[i][0], dp[i][1]);
		}
		else if (v[i] == 2) // A B
		{
			dp[i + 1][1] = min(dp[i][0], dp[i][2]);
		}
		else if (v[i] == 3) // A B C
		{
			dp[i + 1][1] = min(dp[i][0], dp[i][2]);
			dp[i + 1][2] = min(dp[i][0], dp[i][1]);
		}
	}
	printf("%d\n", min( min(dp[n][0], dp[n][1]), dp[n][2]));
    return 0;
}