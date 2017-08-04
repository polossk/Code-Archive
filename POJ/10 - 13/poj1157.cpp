/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] F
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\F.cpp
* @date         :2014/07/16 11:59
* @algorithm    :DP
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

const int MaxN = 105;
const int INF  = 100000;
int f, v;
int a[MaxN][MaxN], dp[MaxN][MaxN];

//  dp[i][j]表示前i束花插入到前j个花瓶里所产生的最大的美学价值
//  转移方程：当j小于i时，连续赋值；超过之后，判断是否添加新的花即可
//  (j <= i): dp[i][j] = dp[i - 1][j - 1] + a[i][j]; 
//  (j > i ): dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j - 1])

void solve()
{
    for (int i = 1; i <= f; i++)
        for (int j = 1; j <= v; j++)
            scanf("%d", &a[i][j]);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= f; i++)
        for (int j = 0; j <= v; j++)// 初值设置
            dp[i][j] = -INF;
    for (int i = 1; i <= f; i++)
        for (int j = i; j <= v - f + i; j++)
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + a[i][j]);
    printf("%d\n", dp[f][v]);
}

int main()
{
	while (~scanf("%d%d", &f, &v)) solve();
	return 0;
}
