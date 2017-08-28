/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] E
#       @file         :E.cpp
#       @date         :2014/07/10 20:55
#       @algorithm    :luan gao
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

int n, m, x, y, z, p;

inline void /*Rotate_R*/RR(int& a, int& b)
{
    int t = a; swap(a, b);
    b = n - t + 1; swap(n, m);
}

inline void /*Rotate_H*/RH(int& a, int& b)
{
    b = m - b + 1;
}

inline void /*Rotate_L*/RL(int& a, int& b)
{
    int t = b; swap(a, b);
    a = m - t + 1; swap(n, m);
}

void solve()
{
    int tn = n, tm = m;
    x %= 4, y %= 2, z %= 4;
    for (int i = 0; i < p; i++)
    {
        int a, b; cin >> a >> b;
        n = tn, m = tm;
        for (int j = 0; j < x; j++) RR(a, b);
        for (int j = 0; j < y; j++) RH(a, b);
        for (int j = 0; j < z; j++) RL(a, b);
        cout << a << " " << b << endl;
    }
}

int main()
{
    while (cin >> n >> m >> x >> y >> z >> p) solve();
    return 0;
}
