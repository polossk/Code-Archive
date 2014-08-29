/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] B
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\B.cpp
* @date         :2014/07/16 11:46
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

typedef long long int64;

const int MaxN = 105;
int n, a[MaxN][MaxN], dp[MaxN][MaxN];

//  dp[i][j]表示，走到(i, j)时的最大值
//  转移方程
//  dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1])

void solve()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
		{
			int t1 = 0, t2 = 0;
			if (i - 1 >= 0) t1 = dp[i - 1][j];
			if (i - 1 >= 0 && j - 1 >= 0) t2 = dp[i - 1][j - 1];
			dp[i][j] = max(t1, t2) + a[i][j];
		}
	int ans = 0;
	for (int j = 0; j < n; j++)
		updateMax(ans, dp[n - 1][j]);
	printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d", &n)) solve();
	return 0;
}
