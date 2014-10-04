/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] A
#       @file         :A.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :Number Theory
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }

int t, tt, m, n;

int getSum(int n, int x)
{
    int ans = 0;
    while (n) ans += n / x,  n /= x;
    return ans;
}

void solve()
{
    cin >> m >> n;
    printf("Case %d:\n", ++tt);
    int i = 2, ans = 1000000000, tmp = 0;
    while (m > 1)
    {
        int a = 0;
        while (m % i == 0) m /= i, a++;
        if (a) tmp = getSum(n, i) / a, updateMin(ans, tmp);
        if (i == 2) i--;
        i += 2;
    }
    if (ans) printf("%d\n", ans);
    else puts("Impossible to divide");
}

int main()
{
    cin >> t; while (t--) solve();
    return 0;
}
