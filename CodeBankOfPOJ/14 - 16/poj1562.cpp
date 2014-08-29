/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] H
#       @file         :H.cpp
#       @date         :2014/07/14 21:04
#       @algorithm    :DFS
******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MaxL = 105;
char grid[MaxL][MaxL];
int sum, m, n;
int dx[] = { 0,  0, -1, -1, -1,  1,  1,  1};
int dy[] = { 1, -1,  1,  0, -1,  1,  0, -1};

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }


void dfs(int x, int y)
{
    if (inbound(x, 0, m) && inbound(y, 0, n) && grid[x][y] == '@')
    {
        grid[x][y] = '*';
        for (int i = 0; i < 8; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            dfs(a, b);
        }
    }
}

void solve()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &grid[i][j]);
    sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '@')
    {
        dfs(i, j);
        sum++;
    }
    printf("%d\n", sum);
}

int main()
{
    while(~scanf("%d%d", &m, &n) && m && n)
        solve();
    return 0;
}
