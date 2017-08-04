/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] E
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\E.cpp
* @date         :2014/07/16 11:59
* @algorithm    :DP
******************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
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

typedef long long int64;
const int MaxL = 105;
int dp[MaxL][MaxL], grid[MaxL][MaxL];
int n, m;

//  最长下降的路
//  dp[i][j]表示到节点(i, j)的最大值
//  转移方程：判断四个方向哪一个满足条件并且更大即可
//  dp[i][j] = max(dp[i - 1][j] + 1, dp[i + 1][j] + 1,
//  			dp[i][j - 1] + 1, dp[i][j + 1] + 1);
//  ans = max{dp[i][j]};
//  利用记忆化搜索进行处理，这样可以减少计算

int dfs(int x, int y)
{
    if (dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;
    if ((grid[x - 1][y] < grid[x][y]) && (x >= 1))
        dp[x][y] = max(dp[x][y], dfs(x - 1, y) + 1);
    if ((grid[x + 1][y] < grid[x][y]) && (x + 1 < n))
        dp[x][y] = max(dp[x][y], dfs(x + 1, y) + 1);
    if ((grid[x][y - 1] < grid[x][y]) && (y >= 1))
        dp[x][y] = max(dp[x][y], dfs(x, y - 1) + 1);
    if ((grid[x][y + 1] < grid[x][y]) && (y + 1 < m))
        dp[x][y] = max(dp[x][y], dfs(x, y + 1) + 1);
    return dp[x][y];
}

void solve()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);
    memset(dp, false, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            updateMax(ans, dfs(i, j));
    printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d%d", &n, &m)) solve();
	return 0;
}
