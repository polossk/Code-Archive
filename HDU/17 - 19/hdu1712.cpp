/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] D
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][7][0717]背包问题\D.cpp
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

const int MaxN = 105;
int a[MaxN][MaxN];
int n, m, dp[MaxN];

// 分组背包  
// dp[v] = max(dp[v], dp[v - c[i]] + w[i]);

void solve()
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	memset(dp, 0, sizeof(dp));
	for (int x = 0; x < n; x++)
	{
		for (int i = m; i >= 0; i--)
			for (int j = 1; j <= m; j++)
				if (i >= j)
					updateMax(dp[i], dp[i - j] + a[x][j]);
	}
	printf("%d\n", dp[m]);
}

int main()
{
	while (~scanf("%d%d", &n,&m) && n && m) solve();
	return 0;
}