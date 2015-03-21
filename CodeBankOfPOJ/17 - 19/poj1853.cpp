// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
// #pragma comment(linker, "/STACK:1024000000,1024000000")

#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

const int MaxN = 105;
const int MaxM = 10005;
const int INF = 0x3f3f3f3f;

int n, a[MaxN];
double p[MaxN];
int dp[MaxM], path[MaxM];

void print(int u)
{
    if (u - a[path[u]] == 0)
    {
        printf("%d", path[u]);
        return;
    }
    print(u - a[path[u]]);
    printf(" %d", path[u]);
}
            
void solve()
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = nextDbf();
        sum += p[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = p[i] / sum * 10000;
        for (int j = 10000; j >= a[i]; j--)
        {
            if (dp[j - a[i]] && !dp[j])
            {
                dp[j] = dp[j - a[i]];
                path[j] = i;
            }
        }
    }
    int v = 0;
    for (int i = 5000; i != 0; i--) if (dp[i])
    {
        v = i; break;
    }
    print(v); puts("");
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}