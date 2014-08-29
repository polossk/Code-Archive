/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][7] C
* @file         :[NWPU][2014][TRN][7][0717]背包问题\C.cpp
* @date         :2014/07/17 10:54
* @algorithm    :Package
******************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

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

const int MaxM = 105;
int t, n, m, dp[MaxM];
int p[MaxM], h[MaxM], c[MaxM];

// 完全背包
void CompletePack(int cost, int weight)
{
    for (int i = cost; i <= n; i++)
        updateMax(dp[i], dp[i - cost] + weight);
}
// 01背包
void ZeroOnePack(int cost, int weight)
{
    for (int i = n; i >= cost; i--)
        updateMax(dp[i], dp[i - cost] + weight);
}
// 多重背包
void MultiplePack(int cost, int weight, int number)
{
    //如果大于等于金额，就按完全背包处理（此时相当于不限定袋数）
    if (cost * number >= n) { CompletePack(cost, weight); return; }
    int k = 1;
    while (k < number)
    {
        ZeroOnePack(k * cost, k * weight);
        number -= k; k *= 2;
    }
    ZeroOnePack(number * cost, number * weight);
}

void solve()
{
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) scanf("%d%d%d", &p[i], &h[i], &c[i]);
    for (int i = 0; i < m; i++) MultiplePack(p[i], h[i], c[i]);
    printf("%d\n", dp[n]);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
