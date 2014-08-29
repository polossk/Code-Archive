/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] O
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\O.cpp
* @date         :2014/07/16 19:55
* @algorithm    :Greedy
******************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <cmath>
#include <queue>
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
const int MaxN = 3005;
pair<int, int> cow[MaxN], bot[MaxN];
int c, l;

void solve()
{
    for (int i = 0; i < c; i++) scanf("%d%d", &cow[i].first, &cow[i].second);
    for (int i = 0; i < l; i++) scanf("%d%d", &bot[i].first, &bot[i].second);
    sort(cow, cow + c); sort(bot, bot + l);
    int j = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < l; i++)
    {
        while (j < c && cow[j].first <= bot[i].first) pq.push(cow[j++].second);
        while (!pq.empty() && bot[i].second)
        {
            int x = pq.top(); pq.pop();
            if (x < bot[i].first) continue;
            ans++; bot[i].second--;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d%d", &c, &l)) solve();
    return 0;
}
