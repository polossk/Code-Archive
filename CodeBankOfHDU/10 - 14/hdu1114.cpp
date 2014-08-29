/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] A
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][7][0717]背包问题\A.cpp
* @date         :2014/07/17 10:54
* @algorithm    :Package
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

const int INF  = 0x07ffffff;
const int MaxW = 10005;
const int MaxN = 505;
int dp[MaxW], p[MaxN], w[MaxN];
int t, n, v, E, F;

// 完全背包
// 转移方程：
// dp[j] = min(dp[j], dp[j - w[i]] + p[i])

void solve()
{
    scanf("%d%d%d", &E, &F, &n); v = F - E;
    fill(dp + 1, dp + v + 1, INF); dp[0] = 0;
    // for (int i = 1; i <= v; i++)dp[i] = INF; dp[0] = 0;
    for (int i = 0; i < n; i++) scanf("%d%d", &p[i], &w[i]);
    for (int i = 0; i < n; i++)
        for (int j = w[i]; j <= v; j++)
            updateMin(dp[j], dp[j - w[i]] + p[i]);
    if (dp[v] == INF) puts("This is impossible.");
    else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[v]);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
