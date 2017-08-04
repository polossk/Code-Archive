// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 3812                                                 *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
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

inline void out(int x)
{
    if (x > 9) out(x / 10); putchar(x % 10 + '0');
}

typedef unsigned long long uint64;
const int MaxN = 200005;

uint64 dp[MaxN];
int go[MaxN][65], W[405], T[405];

void print(int s, int m)
{
    if (m < 0) return ;
    int i = go[s][m];
    print(s - T[i], m - W[i]);
    if (m - W[i] >= 0) putchar(' ');
    out(i);
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    memset(go, 0, sizeof(go));
    int n = nextInt(), q = nextInt();
    for (int i = 1; i <= n; i++)
    {
        W[i] = nextInt(); T[i] = nextInt();
        int w = W[i], t = T[i];
        for (int j = 200000; j > t; j--)
        {
            uint64 mask = dp[j];
            dp[j] |= dp[j - t] << w;
            for (uint64 o = mask ^ dp[j]; o; o = (o - 1) & o)
                go[j][__builtin_ctzll(o)] = i;
        }
        uint64 c = 1ULL << (w - 1);
        if (~dp[t] & c) go[t][w - 1] = i;
        dp[t] |= c;
    }
    for (int i = 0; i < q; i++)
    {
        int m = nextInt(), s = nextInt();
        if (go[s][m - 1]) print(s, m - 1);
        else printf("No solution!");
        puts("");
    }
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
