// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
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

const int MaxN = 1000005;
int n, m, sum, ans;
int x[MaxN], s[MaxN];

void solve()
{
    for (int i = 1; i <= n; i++) x[i] = nextInt();
    s[0] = 0;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + x[i];
    sum = 0;
    for (int i = 1; i <= m; i++) sum += i * x[i];
    ans = sum;
    for (int i = m + 1; i <= n; i++)
    {
        sum = sum - (s[i - 1] - s[i - m - 1]) + m * x[i];
        updateMax(ans, sum);
    }
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}