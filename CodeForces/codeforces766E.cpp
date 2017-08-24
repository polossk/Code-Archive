// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #396 (Div. 2) E                         *
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

const int MAXN = 100005;

vector<int> a, edge[MAXN];

using point = pair<int, int>;

inline point operator+(const point& a, const point& b)
{
	return { a.first + b.first, a.second + b.second };
}

point dfs(int now, int prev, int hoge, int64& cnt)
{
	point ret = { 0, 0 };
	int flag = (a[now] >> hoge) & 1;
	for (int next : edge[now])
	{
		if (next == prev) continue;
		auto tmp = dfs(next, now, hoge, cnt);
		if (flag)
		{
			cnt += ret.first * tmp.first;
			cnt += ret.second * tmp.second;
		}
		else
		{
			cnt += ret.first * tmp.second;
			cnt += ret.second * tmp.first;
		}
		ret = ret + tmp;
	}
	ret.first += 1;
	if (flag) swap(ret.first, ret.second);
	cnt += ret.second;
	return ret;
}

int main()
{
	int n = nextInt();
	for (int i = 0; i < n; i++) a.push_back(nextInt());
	for (int i = 1; i < n; i++)
	{
		int u = nextInt() - 1;
		int v = nextInt() - 1;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int64 ans = 0, cnt = 0;
	for (int i = 0; i < 20; i++)
	{
		cnt = 0;
		dfs(0, 0, i, cnt);
		ans += (1 << i) * cnt;
	}
	cout << ans << endl;
	return 0;
}