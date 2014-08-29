/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] D
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\D.cpp
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

typedef long long int64;

const int MaxN = 100005;
int a[MaxN], dp[MaxN];
int t, tt, n, s, e;
int ans, fs, fe;

//  最大子串和
//  dp[i]表示到第i个数以i为结尾的子串（包括第i个）的最大值
//  转移方程：判断是添加一个数后更大，还是另外新开一个更大
//  dp[i] = max(dp[i - 1] + a[i], a[i])
//  ans = max{dp[i]};
//  当新开一个时（也就是a[i] > dp[i - 1] + a[i]时），更新左节点
//  否则，更新右节点

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    s = e = 0; dp[0] = a[0];
    ans = a[0]; fs = fe = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] + a[i] >= a[i])
            dp[i] = dp[i - 1] + a[i], e = i;
        else dp[i] = a[i], s = e = i;
        if (ans < dp[i])
            ans = dp[i], fs = s, fe = e;
    }
    printf("Case %d:\n", ++tt);
    printf("%d %d %d\n", ans, fs + 1, fe + 1);
    if (t) puts("");
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
