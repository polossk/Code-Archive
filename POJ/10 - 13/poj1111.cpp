/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] F
#       @file         :F.cpp
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
bool vis[MaxL][MaxL];
int sum, r, c, x, y;
int dx[] = { 0,  0, -1, -1, -1,  1,  1,  1};
int dy[] = { 1, -1,  1,  0, -1,  1,  0, -1};

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }


void dfs(int a, int b)
{
    vis[a][b] = 1;
    for (int i = 0; i < 8; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (inbound(x, 0, r) && inbound(y, 0, c))
        {
            if (grid[x][y] == 'X' && vis[x][y] == 0) dfs(x, y);
            else if (grid[x][y] == '.' && ((x == a) || (y == b))) sum++;
        }
        else if (x == a || y == b)sum++;
    }
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf(" %c", &grid[i][j]);
    sum = 0; dfs(x - 1, y - 1);
    printf("%d\n", sum);
}

int main()
{
    while(~scanf("%d%d%d%d", &r, &c, &x, &y) && r && c && x && y)
        solve();
    return 0;
}
