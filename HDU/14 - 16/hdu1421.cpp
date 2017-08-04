/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] I
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\I.cpp
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

const int MaxN = 2005;
const int INF  = 2147483346; // 初始化小了会WA。。。
int n, k, dp[MaxN][MaxN], a[MaxN];
#define SQR(_) (_) * (_)

//  最小总疲劳度
//  dp[i][j]表示我们表示前i件物品取j对时最少的疲劳度
//  a[i]表示重量，w[i]表示疲劳度开销
//  转移方程：要不就选这个东西，要不不选
//  dp[i][j] = 
//  	min(dp[i - 1][j],					// 不选取第i件
//  		dp[i - 2][j - 1] + w[i - 1])	// 选取第i件
//  边界处理额外注意：所有的不合法的赋值为！极大值！

inline int getDP(int i, int j)
{
    if (i < 2 * j) return INF;
    else if (j == 0) return 0;
    else return dp[i][j];
}

void solve()
{
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) a[i] = SQR(a[i + 1] - a[i]);
    for (int j = 1; j <= k; j++)
        for (int i = 2 * j; i <= n; i++)
    {
        int t1 = getDP(i - 1, j);
        int t2 = getDP(i - 2, j - 1) + a[i - 1];
        dp[i][j] = min(t1, t2);
    }
    printf("%d\n", dp[n][k]);
}

int main()
{
	while (~scanf("%d%d", &n, &k)) solve();
	return 0;
}
