// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2311                                                 *
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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

int sg[205][205];
int n, m;

int dfs(int n, int m)
{
    if (sg[n][m] != -1) return sg[n][m];
    bool vis[1024]; fill(vis, vis + 1024, LOSE);
    for (int i = 2; i <= n - i; i++)
        vis[dfs(i, m) ^ dfs(n - i, m)] = WIN;
    for (int i = 2; i <= m - i; i++)
        vis[dfs(n, i) ^ dfs(n, m - i)] = WIN;
    for (int i = 0; ; i++) if (vis[i] == LOSE)
        return sg[n][m] = i;
}

void solve()
{
    if (dfs(n, m)) puts("WIN");
    else puts("LOSE");
}

int main()
{
    memset(sg, -1, sizeof(sg));
    while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
