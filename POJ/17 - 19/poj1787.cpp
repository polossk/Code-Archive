/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] H
* @file         :[NWPU][2014][TRN][7][0717]背包问题\H.cpp
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
const int INF  = 100000;
const int MaxM = 10005;
const int MaxN = 105;
int n, dp[MaxM], ans[MaxN];
int path[MaxM], used[MaxM];
int num[4], val[4] = {1, 5, 10, 25};

// 完全背包, 同时用path记录路径
// 转移方程：
// dp[j] = max(dp[j], dp[j - val[i]] + 1)

void solve()
{
    for (int i = 0; i < 4; i++) scanf("%d", &num[i]);
    fill(dp + 1, dp + MaxM, -INF); dp[0] = 0;
    memset(path, 0, sizeof(path)); path[0] = -1;
    for (int i = 0; i < 4; i++)
    {
        memset(used, 0, sizeof(used));
        for (int j = val[i]; j <= n; j++)
		{
            if (dp[j-val[i]] != -INF && dp[j] < dp[j - val[i]] + 1
                && used[j - val[i]] + 1 <= num[i]) {
                dp[j] = dp[j - val[i]] + 1;
                used[j] = used[j - val[i]] + 1;
                path[j] = j - val[i];
            }
        }
    }
    memset(ans, 0, sizeof(ans));
    if (dp[n] == -INF) puts("Charlie cannot buy coffee.");
    else
    {
        while (path[n] != -1)
        {
            ans[n - path[n]]++;
            n = path[n];
        }
        printf("Throw in %d cents, %d nickels, ", ans[val[0]], ans[val[1]]);
        printf("%d dimes, and %d quarters.\n", ans[val[2]], ans[val[3]]);
    }
}

int main()
{
	while (~scanf("%d", &n) && n)
        solve();
	return 0;
}
