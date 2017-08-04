/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] H
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\H.cpp
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

const int MaxN = 5005;
int n, dp[2][MaxN];
char str[MaxN];

//  求添加最少的字符使其变为回文串
//  答案是字符串长度N减去该字符串s1与其本身的反转s2的最长公共子串的长度
//  即，ans = N - LCS(s1, s2)
//  最长公共子串的长度的求解
//  dp[i][j]表示，分别到a[i]和b[j]结束的串，最长公共子串的长度
//  转移方程：相同则加1，不同则取最大的
//  if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
//  else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//  本题需要用01滚动法，因为空间太小
//  具体做法是在i下标处做模2运算即可
//  则最后答案为ans = n - dp[n % 2][n]

void solve()
{
    scanf("%s", str + 1);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)// 字符串从下标1开始
        for (int j = n; j >= 1; j--)
    {
        if (str[i] == str[j])
            dp[i % 2][n - j + 1] = dp[(i - 1) % 2][n - j] + 1;
        else
            dp[i % 2][n - j + 1] = max(dp[(i - 1) % 2][n - j + 1], dp[i % 2][n - j]);
    }
    int ans = n - dp[n % 2][n];
    printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d", &n)) solve();
	return 0;
}
