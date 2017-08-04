/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRM][2] C
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRM][2][0715]前面的一定不是水题\C.cpp
* @date         :2014/07/15 18:38
* @algorithm    :Simulation
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 105;
int remain, chance, t;
bool win, lose;
string s, g;

void guess(char ch)
{
    bool bad = 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ch)
            remain--, s[i] = ' ', bad = 0;
    if (bad) chance--;
    if (!chance) lose = 1;
    if (!remain) win = 1;
}

void solve()
{
    cin >> s >> g;
    printf("Round %d\n", t);
    win = lose = false;
    remain = s.size();
    chance = 7;
    int sz = g.size();
    for (int i = 0; i < sz; i++)
    {
        guess(g[i]);
        if (win || lose) break;
    }
    if (win) printf("You win.\n");
    else if (lose) printf("You lose.\n");
    else printf("You chickened out.\n");
}

int main()
{
    while (~scanf("%d", &t) && t != -1)
        solve();
    return 0;
}
