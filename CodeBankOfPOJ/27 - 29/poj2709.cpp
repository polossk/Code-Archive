/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] M
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\M.cpp
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

bool cmp(int a, int b) { return a > b; }
int n, need[20], remain[20];

void solve()
{
    int ans = 0, tmp = 0, l = 0, gray = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &need[i]);
        updateMax(l, need[i]);
    }
    scanf("%d", &gray);
    if (l % 50 == 0) tmp = l / 50;
    else tmp = l / 50 + 1;
    for (ans = tmp; ; ans++)
    {
        int k = gray;
        for (int j = 0; j < n; j++) remain[j] = ans * 50 - need[j];
        while (true)
        {
            sort(remain, remain + n, cmp);
            if (remain[2] <= 0)
            {
                if (k <= 0) flag = 1;
                break;
            }
            k--;
            for (int j = 0; j < 3; j++) remain[j]--;
        }
        if (flag) break;
    }
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}
