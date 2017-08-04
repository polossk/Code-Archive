// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2068                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
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

const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";
const bool WIN  = true;
const bool LOSE = false;

short dp[20][8196];
int a[20], n, s;

short dfs(int id, int remain)
{
    if (dp[id][remain] != 0x3f3f) return dp[id][remain];
    if (remain == 0) return dp[id][remain] = WIN;
    dp[id][remain] = LOSE;
    for (int i = 1; i <= a[id] && i <= remain; i++)
        if (!dfs((id + 1) % n, remain - i))
            dp[id][remain] = WIN;
    return dp[id][remain];
}

void solve()
{
    s = nextInt();
    for (int i = 0; i < n; i++) a[i] = nextInt();
    memset(dp, 0x3f, sizeof(dp));
    printf("%d\n", dfs(0, s));
}

int main()
{
    while (n = nextInt() * 2) solve();
    return 0;
}
