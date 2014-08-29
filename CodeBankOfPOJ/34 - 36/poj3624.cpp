/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] I
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][7][0717]背包问题\I.cpp
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

const int MaxN = 100005;
int v[MaxN], w[MaxN], dp[MaxN];
int n, V;

// 01背包
// 转移方程：
// dp[j] = min(dp[j], dp[j - w[i]] + v[i])

void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%d%d", &w[i], &v[i]);
    for (int i = 0; i < n; i++)
        for (int j = V; j >= w[i]; j--)
            updateMax(dp[j], dp[j - w[i]] + v[i]);
    printf("%d\n", dp[V]);
}

int main()
{
	while (~scanf("%d%d", &n, &V)) solve();
	return 0;
}

