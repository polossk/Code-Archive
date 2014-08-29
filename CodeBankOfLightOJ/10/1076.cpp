// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1076                                             *
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

const int maxN = 1005;

int a[maxN];
int t, tt;
int n, m;

inline bool test(int x)
{
	int sum = 0, cnt = 1;
	for (int i = 0; i < n; i++)
    {
		sum += a[i];
		if (sum > x) sum = a[i], cnt++;
	}
	return cnt > m;
}

int Bsearch(int l, int r)
{
    while (r > l)
    {
        int mid = (r + l) / 2;
        if (test(mid)) l = mid + 1;
        else r = mid;
    }
    return r;
}

void solve()
{
    n = nextInt(); m = nextInt();
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = nextInt();
        if (a[i] > l) l = a[i];
        r += a[i];
    }
    int res = Bsearch(l, r);
    printf("Case %d: %d\n", ++tt, res);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
