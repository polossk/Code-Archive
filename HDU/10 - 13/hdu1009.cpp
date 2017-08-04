/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] K
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\K.cpp
* @date         :2014/07/16 19:58
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

struct node
{
    double J, F, c;
    bool operator<(const node& t) const
    {
        return c > t.c;
    }
};
const int MaxM = 1005;
int n, m;
node data[MaxM];

void solve()
{
    double ans = 0, t = double(n);
    for (int i = 0; i < m; i++)
    {
        scanf("%lf%lf", &data[i].J, &data[i].F);
        data[i].c = data[i].J / data[i].F;
    }
    sort(data, data + m);
    for (int i = 0; i < m; i++)
    {
        if (data[i].F <= t)
            ans += data[i].J, t -= data[i].F;
        else { ans += t * data[i].c; break; }
    }
    printf("%.3lf\n", ans);
}

int main()
{
    while (~scanf("%d%d", &n, &m) && n != -1 && m != -1)
        solve();
    return 0;
}
