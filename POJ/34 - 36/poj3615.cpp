/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] P
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\P.cpp
* @date         :2014/07/16 19:55
* @algorithm    :Floyd
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

const int MaxN = 305;
const int INF  = 1111111;
int n, m, q;
int grid[MaxN][MaxN], dis[MaxN][MaxN];

typedef long long int64;

void floyd()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = grid[i][j];
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
}

void solve()
{
    int s = 0, t = 0, d = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            grid[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &s, &t, &d);
        grid[s][t] = d;
    }
    floyd();
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &s, &t);
        printf("%d\n", (dis[s][t] >= INF)? -1: dis[s][t]);
    }
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &q)) solve();
    return 0;
}
