/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] E
#       @file         :E.cpp
#       @date         :2014/07/14 16:44
#       @algorithm    :BFS
******************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int dx[] = { 1, -1,  0,  0};
int dy[] = { 0,  0,  1, -1};

const int MaxL = 6;
int fa[MaxL][MaxL];
bool vis[MaxL][MaxL];
bool grid[MaxL][MaxL];

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }

inline bool inbound(int u)
{
    int x = u / 5, y = u % 5;
    return !grid[x][y] && inbound(x, 0, 5) && inbound(y, 0, 5);
}

inline int encode(int x, int y) { return x * 5 + y; }

inline int newPos(int old, int method)
{
    int x = old / 5, y = old % 5;
    x += dx[method], y += dy[method];
    if (inbound(x, 0, 5) && inbound(y, 0, 5)) return encode(x, y);
    else return -1;
}

bool bfs(int beg, int tar)
{
    memset(fa, 0, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    queue<int> q; q.push(beg);
    vis[beg / 5][beg % 5] = 1;
    fa[beg / 5][beg % 5] = 0;
    while (!q.empty())
    {
        int top = q.front(); q.pop();
        if (top == tar) break;
        for (int j = 0; j < 4; j++)
        {
            int tmp = newPos(top, j);
            if (tmp != -1 && inbound(tmp) && !vis[tmp / 5][tmp % 5])
            {
                vis[tmp / 5][tmp % 5] = 1;
                fa[tmp / 5][tmp % 5] = top;
                q.push(tmp);
            }
        }
    }
    return false;
}

void path_print(int tar)
{
    int nx = tar / 5, ny = tar % 5;
    int fn = fa[nx][ny];
    int fx = fn / 5, fy = fn % 5;
    if (fx != nx || fy != ny)
    {
        path_print(encode(fx, fy));
        printf("(%d, %d)\n", nx, ny);
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> grid[i][j];
    int beg = encode(0, 0), tar = encode(4, 4);
    puts("(0, 0)");
    bfs(beg, tar);
    path_print(tar);
    return 0;
}
