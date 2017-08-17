// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   C                                                        *
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

const int MaxN = 1024;
int n, k, d, sum;
int a[MaxN], m[MaxN][MaxN];

void dfs(int cur)
{
    if (sum >= n) return;
    if (cur >= d)
    {
        for (int i = 0; i < d; i++) m[i][sum] = a[i];
        sum++; return;
    }
    for (int i = 1, endflag = min(k, 1001); i <= endflag; i++)
    {
        a[cur] = i; dfs(cur + 1);
    }
}

void solve()
{
    sum = 0; memset(m, 0, sizeof(m));
    dfs(0);
    if (sum < n) puts("-1");
    else for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < n; j++) printf("%d ", m[i][j]);
        puts("");
    }
}

int main()
{
    while (~scanf("%d%d%d", &n, &k, &d)) solve();
    return 0;
}