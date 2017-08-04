/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] A
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\A.cpp
* @date         :2014/07/16 10:58
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

#include <vector>

int tt, s, i;
vector<int> a(100005), dp(100005);

//  dp[i]表示，前i个数组成的序列中，最长的非增序列的长度
//  转移方程 ( 0 <= k < j )
//  if (a[j] < a[k] && dp[j] <= dp[k]) dp[j] = 1 + dp[k];

void solve()
{
	int n = i + 1; dp[0] = 1;
	for (int j = 1; j < n; j++)
	{
		dp[j] = 1;
		for (int k = 0; k < j; k++)
		{
			if (a[j] < a[k] && dp[j] <= dp[k]) dp[j] = dp[k] + 1;
		}
	}
	int ans = 0;
	for (int j = 0; j < n; j++)
		updateMax(ans, dp[j]);
	printf("Test #%d:\n", ++tt);
	printf("  maximum possible interceptions: %d\n\n", ans);
}

int main()
{
	while (~scanf("%d", &s) && s != -1)
	{
		i = 0; a[0] = s;
		while (~scanf("%d", &s) && s != -1)
			a[++i] = s;
		solve();
	}
	return 0;
}
