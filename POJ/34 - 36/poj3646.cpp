/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] L
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\L.cpp
* @date         :2014/07/16 19:57
* @algorithm    :Greedy
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

const int MaxN = 20005;
int a[MaxN], b[MaxN];
int n, m;

void solve()
{
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(a, a + n); sort(b, b + m);
    int cur = 0, cost = 0;
    for (int i = 0; i < m; i++)
        if (b[i] >= a[cur])
    {
        cost += b[i];
        if (++cur == n) break;
    }
    if (cur < n) puts("Loowater is doomed!");
    else printf("%d\n", cost);
}

int main()
{
    while (~scanf("%d%d", &n, &m) && n && m) solve();
    return 0;
}
