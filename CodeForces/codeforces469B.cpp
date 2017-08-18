// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #268 Div.2 B                                             *
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

const int MaxL = 64;
int p, q, l, r;
int a[MaxL], b[MaxL];
int c[MaxL], d[MaxL];

inline bool inBound(int x, int l, int r)
{
	return x <= r && x >= l;
}

inline bool testCross(int cc, int dd)
{
	for (int i = 0; i < p; i++)
	{
		if (inBound(cc, a[i], b[i])) return true;
		else if (cc > b[i]) continue;
		else if (dd >= a[i]) return true;
		else continue;
	}
	return false;
}

void solve()
{
	p = nextInt(); q = nextInt();
	l = nextInt(); r = nextInt();
	for (int i = 0; i < p; i++)
	{
		a[i] = nextInt();
		b[i] = nextInt();
	}
	for (int i = 0; i < q; i++)
	{
		c[i] = nextInt();
		d[i] = nextInt();
	}
	int ans = 0;
	for (int i = l; i <= r; i++)
	{
		bool flag = false;
		for (int j = 0; j < q; j++)
		{
			int nowc = i + c[j], nowd = i + d[j];
			flag = testCross(nowc, nowd);
			if (flag) break;
		}
		if (flag) ans++;
	}
	printf("%d\n", ans);
}

int main()
{
	solve();
    return 0;
}