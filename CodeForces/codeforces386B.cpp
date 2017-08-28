/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] B
#       @file         :B.cpp
#       @date         :2014/07/10 20:44
#       @algorithm    :luan gao
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

int n, t, s[1024];

int result()
{
    int res = -1, d = 0;
    for (int i = 0; i < n; i++)
    {
        for (d = 0; i + d < n; d++)
            if (s[i + d] - s[i] > t) break;
        updateMax(res, d);
    }
    return res;
}

void solve()
{
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    scanf("%d", &t);
    sort(s, s + n);
    int ans = result();
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}
