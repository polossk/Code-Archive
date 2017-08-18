// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #268 Div.2 A                                             *
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

const char aye[] = "I become the guy.";
const char nay[] = "Oh, my keyboard!";

bool vis[105];
int n, p, q;

void solve()
{
	fill(vis, vis + 105, 0);
	n = nextInt();
	p = nextInt();
	for (int i = 0; i < p; i++) vis[nextInt()] = 1;
	q = nextInt();
	for (int i = 0; i < q; i++) vis[nextInt()] = 1;
	bool flag = 1;
	for (int i = 1; i <= n; i++) flag &= vis[i];
	puts(flag? aye: nay);
}

int main()
{
	solve();
    return 0;
}