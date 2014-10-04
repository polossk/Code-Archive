/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] B
#       @file         :B.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :Number Theory
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
int64 n;

void solve()
{
    int64 ntemp = n;
    int64 cnt = 0, ans = 1;
    for (int64 i = 2; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            cnt = 0;
            while (n % i == 0) n/= i, cnt++;
            ans *= (cnt << 1) + 1;
        }
        if (i == 2) i--;        // 从3开始接着分解质因数
    }
    if (n > 1) ans += ans << 1; // ans = ans * 3;
    ans = (ans >> 1) + 1;       // ans = (ans + 1) / 2
    cout << ntemp << " " << ans << endl;
}

int main()
{
    while (cin >> n && n) solve();
    return 0;
}
