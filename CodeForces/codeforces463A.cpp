// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #264 Div.2 A                                             *
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

const int MaxN = 205;
int x[MaxN], y[MaxN];
int n, s;

void solve()
{
    for (int i = 0; i < n; i++)
		x[i] = nextInt(), y[i] = nextInt();
	s *= 100;
	int ans = -1;
	for (int i = 0; i < n; i++)
		if (s >= x[i] * 100 + y[i])
    {
			int tmp = (s - x[i] * 100 - y[i]) % 100;
			updateMax(ans, tmp);
    }
	cout << ans << endl;
}

int main()
{
    cin >> n >> s;
    solve();
    return 0;
}