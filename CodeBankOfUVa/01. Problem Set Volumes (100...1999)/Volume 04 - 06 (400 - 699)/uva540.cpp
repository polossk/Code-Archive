/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][2] D
#       @file         :G:\My Source Code\【ACM】训练\0711 - [NWPU][SRM][2]\D.cpp
#       @date         :2014-07-11 19:23
#       @algorithm    :Queue Simulation
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, tt;
const int MaxT = 1010;


void solve()
{
    map<int, int> team;
    queue<int> group, meber[MaxT];
    printf("Scenario #%d\n", ++tt);
    for (int i = 0; i < n; i++)
    {
        int t, x;
        scanf("%d", &t);
        while (t--) { scanf("%d", &x); team[x] = i; }
    }
    while (1)
    {
        int x; char cmd[10];
        scanf("%s", cmd);
        if (cmd[0] == 'S') break;
        else if (cmd[0] == 'D')
        {
            int t = group.front();
            printf("%d\n", meber[t].front()); meber[t].pop();
            if (meber[t].empty()) group.pop();
        }
        else if (cmd[0] == 'E')
        {
            scanf("%d", &x); int t = team[x];
            if (meber[t].empty()) group.push(t);
            meber[t].push(x);
        }
    }
    puts("");
}

int main()
{
    //freopen("a.out", "w", stdout);
    while (~scanf("%d", &n) && n) solve();
	return 0 ;
}
