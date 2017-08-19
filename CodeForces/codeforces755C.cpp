// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   8VC Venture Cup 2017 - Elimination Round C               *
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

const int MAXN = 50003;
int fa[MAXN], rk[MAXN];

inline void init(int n)
{
    fill(rk, rk + n, 0); n++;
    while (n--) fa[n] = n;
}

inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }

inline bool Query(int x, int y) { return _find(x) == _find(y); }

void Merge(int x, int y)
{
    x = _find(x); y = _find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) fa[x] = y;
    else { fa[y] = x; rk[x] += (rk[x] == rk[y]); }
}


int main()
{
	int n = nextInt(); init(n);
	for (int i = 1; i <= n; i++)
	{
		int _ = nextInt(); Merge(i, _);
		// cout << i << ", " << _ << endl;
		// cout << fa[i] << ", " << fa[_] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		// cout << fa[i] << ", ";
		ans += (i == fa[i]);
	}
	cout << ans << endl;
	return 0;
}