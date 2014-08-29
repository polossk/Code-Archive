/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] J
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][5][0714]二分与贪心\J.cpp
* @date         :2014/07/16 19:54
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

struct Show
{
    int s, e;
    bool operator<(const Show& t) const
    {
        return e < t.e;
    }
};
const int MaxN = 10005;
Show data[MaxN];
int n;

void solve()
{
    for (int i = 0; i < n; i++)
        scanf("%d%d", &data[i].s, &data[i].e);
    sort(data, data + n);
    int ans = 1, len = data[0].e;
    for (int i = 1; i < n; i++)
        if (len <= data[i].s)
            ans++, len = data[i].e;
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}
