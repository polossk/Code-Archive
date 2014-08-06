// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1249                                             *
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

struct package
{
    char name[25];
    int sum;
    inline bool operator<(const package& p) const { return sum < p.sum; }
};

package a[105];
int t, tt, n;

void solve()
{
    n = nextInt();
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d%d", a[i].name, &x, &y, &z);
        a[i].sum = x * y * z;
    }
    sort(a, a + n);
    if (a[0].sum == a[n - 1].sum)
        printf("Case %d: no thief\n", ++tt);
    else printf("Case %d: %s took chocolate from %s\n", ++tt, a[n - 1].name, a[0].name);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
