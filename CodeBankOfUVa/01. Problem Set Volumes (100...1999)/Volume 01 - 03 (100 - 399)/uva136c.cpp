/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] E
#       @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\0711 - [NWPU][SRM][2]\E3.cpp
#       @date         :2014-07-11 19:21
#       @algorithm    :DP
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int root[3] = {2, 3, 5};
int x, y, z;
int res[1505];

inline int min(int a, int b, int c) { return min(a, min(b,c)); }

int UNgenerater(int n)
{
    x = y = z = 1;
    for (int i = 2; i <= n; i++)
    {
        int t1 = 2 * res[x];
        int t2 = 3 * res[y];
        int t3 = 5 * res[z];
        res[i] = min(t1, t2, t3);
        if (res[i] == t1) x++;
        if (res[i] == t2) y++;
        if (res[i] == t3) z++;
    }
    return res[n];
}

int main()
{
    res[0] = res[1] = 1;
    cout << "The 1500'th ugly number is " << UNgenerater(1500) << "." << endl;
    return 0;
}
