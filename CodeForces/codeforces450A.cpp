/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :A
* @file         :G:\My Source Code\【ACM】比赛\0719 - CF\A.cpp
* @date         :2014/07/19 20:57
* @algorithm    :Simulation
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

int n, m, tmp;
int a[105];

int main()
{
    cin >> n >> m;
    queue<int> id, cand;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        id.push(i + 1); cand.push(a[i]);
    }
    while (id.size() != 1)
    {
        int top = cand.front();
        int x = id.front();
        //cout << x << " " << top << endl;
        if (top > m)
        {
            id.pop(); cand.pop();
            id.push(x); cand.push(top - m);
        }
        else
        {
            cand.pop(); id.pop();
        }
    }
    int res = id.front();
    cout << res << endl;
    return 0;
}
