/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] D
#       @file         :D.cpp
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

int dx[] = { 1,  2,  2,  1, -1, -2, -2, -1};
int dy[] = { 2,  1, -1, -2, -2, -1,  1,  2};
const int MaxL = 310;
int step[MaxL][MaxL];
bool vis[MaxL][MaxL];

int t, l, nx, ny, fx, fy;

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }

inline bool inbound(int u, int size = l)
{
    int x = u / size, y = u % size;
    return inbound(x, 0, size) && inbound(y, 0, size);
}

inline int encode(int x, int y, int size = l) { return x * size + y; }

inline int newPos(int old, int method, int size = l)
{
    int x = old / size, y = old % size;
    x += dx[method], y += dy[method];
    if (inbound(x, 0, size) && inbound(y, 0, size)) return encode(x, y);
    else return -1;
}

int bfs(int beg, int tar, int size = l)
{
    memset(step, 0, sizeof(step));
    memset(vis, 0, sizeof(vis));
    queue<int> q; q.push(beg);
    vis[beg / size][beg % size] = 1;
    while (!q.empty())
    {
        int top = q.front(); q.pop();
        if (top == tar) break;
        for (int j = 0; j < 8; j++)
        {
            int tmp = newPos(top, j);
            if (tmp != -1 && inbound(tmp) && !vis[tmp / size][tmp % size])
            {
                vis[tmp / size][tmp % size] = 1;
                step[tmp / size][tmp % size] = step[top / size][top % size] + 1;
                q.push(tmp);
            }
        }
    }
    return step[tar / size][tar % size];
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d%d", &l, &nx, &ny, &fx, &fy);
        int beg = encode(nx, ny);
        int tar = encode(fx, fy);
        printf("%d\n", bfs(beg, tar));
    }
    return 0;
}
