// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2259 (G++ only)                                      *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

// #include <bits/stdc++.h>
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

int n, tt;
const int MaxT = 1010;

void solve()
{
    map<int, int> team;
    queue<int> group, meber[MaxT];
    printf("Scenario #%d\n", ++tt);
    for (int i = 0; i < n; i++)
    {
        int t, x;
        scanf("%d", &t);
        while (t--) { scanf("%d", &x); team[x] = i; }
    }
    while (1)
    {
        int x; char cmd[10];
        scanf("%s", cmd);
        if (cmd[0] == 'S') break;
        else if (cmd[0] == 'D')
        {
            int t = group.front();
            printf("%d\n", meber[t].front()); meber[t].pop();
            if (meber[t].empty()) group.pop();
        }
        else if (cmd[0] == 'E')
        {
            scanf("%d", &x); int t = team[x];
            if (meber[t].empty()) group.push(t);
            meber[t].push(x);
        }
    }
    puts("");
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
	return 0 ;
}
