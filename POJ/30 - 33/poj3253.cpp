/**============================================================================
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :POJ 3253
#       @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\0624 - »ù´¡\poj3253.cpp
#       @date         :2014-06-24 14:45
#       @algorithm    :Greedy
============================================================================**/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <queue>
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

int n, l;

void solve()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l);
        pq.push(l);
    }
    int64 ans = 0;
    if (n == 1) ans = l;
    while (pq.size() > 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + b;
        ans += c; pq.push(c);
    }
    printf("%lld\n", ans);
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}