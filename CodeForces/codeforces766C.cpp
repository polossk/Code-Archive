// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #396 (Div. 2) C                         *
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

const int MAXN = 1024;
const int MOD = 1000000007;

int main()
{
	int n = nextInt();
	string s = nextStr();
	vector<int> a, dp(MAXN, 0), tmp(MAXN, 0);
	for (int i = 0; i < 26; i++) a.push_back(nextInt());
	int len = 0; dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int hoge = n;
		tmp[i] = i;
		for (int j = i - 1; j >= 0; j--)
		{
			updateMin(hoge, a[s[j] - 'a']);
			if (i - j > hoge) break;
			updateMax(len, i - j);
			dp[i] = (dp[i] + dp[j]) % MOD;
			updateMin(tmp[i], 1 + tmp[j]);
		}
	}
	cout << dp[n] << endl;
	cout << len << endl;
	cout << tmp[n] << endl;
	return 0;
}