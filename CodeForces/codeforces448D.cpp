/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :D
#       @file         :D.cpp
#       @date         :2014/07/17 22:47
#       @algorithm    :Binary Search
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

int64 n, m, k;

bool check(int64 x)
{
    int64 res = 0;
    for (int i = 1; i <= n; i++)
    {
        int64 tmp = min(i * m, x);
        res += tmp / i;
    }
    return res < k;
}

// 从小往大 计数，第k个
int64 BinarySearch(int64 l, int64 r)
{
    while (l < r)
    {
        int64 mid = (l + r) / 2;
        //cout << l << " " << mid << " " << r << endl;
        //cout << "check result: " << check(mid);
        if (check(mid)) l = mid + 1;
        else r = mid;
        //system("pause");
    }
    return r;
}

int main()
{
    cin >> n >> m >> k;
    int64 Right = n * m, Left = 1;
    int64 ans = BinarySearch(Left, Right);
    cout << ans;
    return 0;
}
