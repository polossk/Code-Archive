/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] G
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][7][0717]背包问题\G.cpp
* @date         :2014/07/17 10:54
* @algorithm    :Package
******************************************************************************/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

const int MaxN = 50005;
int dp[MaxN], c[11], w[11];
int t, n, v, y;

// 完全背包
// 转移方程：
// dp[j] = min(dp[j], dp[j - c[i]] + w[i])

void solve()
{
    scanf("%d%d%d", &v, &y, &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d%d", &c[i], &w[i]), c[i] /= 1000;
    int res = v;
    while (y--)
    {
        v /= 1000;
        for (int i = 0; i < n; i++)
            for (int j = c[i]; j <= v; j++)
                updateMax(dp[j], dp[j - c[i]] + w[i]);
        res += dp[v]; v = res;
    }
    printf("%d\n", v);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
