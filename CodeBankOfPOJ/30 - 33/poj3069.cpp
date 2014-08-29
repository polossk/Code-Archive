/**============================================================================
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :POJ 3069
#       @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\0624 - »ù´¡\poj3069.cpp
#       @date         :2014-06-24 14:33
#       @algorithm    :Greedy
============================================================================**/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

int r, n;
int x[1005];

void solve()
{
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    sort(x, x + n);
    int i = 0, ans = 0;
    while (i < n)
    {
        int s = x[i++];
        while (i < n && x[i] <= s + r) i++;
        int p = x[i - 1];
        while (i < n && x[i] <= p + r) i++;
        ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d%d", &r, &n))
    {
        if (r == -1 && n == -1) break;
        else solve();
    }
    return 0;
}