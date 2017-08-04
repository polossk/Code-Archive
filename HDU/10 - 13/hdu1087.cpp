/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] J
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\J.cpp
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

const int MaxN = 1005;
int n, a[MaxN], dp[MaxN];

//  最大上升子序列的和LIS
//  dp[i]表示，前i个数组成的序列中，最长的非增序列的长度
//  转移方程 ( 0 <= j < i )
//  if (a[i] > a[j] && dp[i] < dp[j] + a[i]) dp[i] = a[i] + dp[j];

void solve()
{
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = a[i];
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && dp[i] < dp[j] + a[i])
                dp[i] = a[i] + dp[j];
    }
    int ans = dp[0];
    for (int i = 1; i < n; i++) updateMax(ans, dp[i]);
    printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d", &n) && n) solve();
	return 0;
}
