/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][2] C
#       @file         :G:\My Source Code\【ACM】训练\0711 - [NWPU][SRM][2]\C.cpp
#       @date         :2014-07-11 19:23
#       @algorithm    :Simulation
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, tt;
int a[15], b[15], c[15];
const int MaxR = 2520;

void solve()
{
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    int ans = 1;
    while (ans < MaxR)
    {
        int awake = 0, sleep = 0;
        for (int i = 0; i < n; i++)
            awake += (c[i] <= a[i]);
        sleep = n - awake;
        if (sleep == 0) break;
        else
        {
            for (int i = 0; i < n; i++)
            {
                c[i]++;
                if (c[i] == a[i] + b[i] + 1) c[i] = 1;
                if (c[i] == a[i] + 1 && awake >= sleep) c[i] = 1;
            }
        }
        ans++;
    }
    printf("Case %d: %d\n", ++tt, (ans == 2520)? -1: ans);
}

int main(){
    while (cin >> n && n) solve();
    return 0;
}
