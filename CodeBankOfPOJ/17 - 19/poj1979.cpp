/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] B
#       @file         :B.cpp
#       @date         :2014/07/13 15:13
#       @algorithm    :DFS
******************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int64;
int w, h, cnt;
char gird[25][25];
//driection u,  d,  r,  l;
int dx[4] = { 0,  0,  1, -1};
int dy[4] = {-1,  1,  0,  0};

inline bool inbound(int l, int r, int x)
{
    return (x >= l && x < r);
}

inline bool check(int x, int y)
{
    return inbound(0, w, x) && inbound(0, h, y);
}

void dfs(int x, int y)
{
    if (!check(x, y)) return;
    else if (gird[x][y] == '@' || gird[x][y] == '.')
    {
        cnt++;
        gird[x][y] = '#';
        for (int i = 0; i < 4; i++)
            dfs(x + dx[i], y + dy[i]);
    }
}

void solve()
{
    memset(gird, 0, sizeof(gird));
    int sx = 0, sy = 0; cnt = 0;
    for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
    {
        scanf(" %c", &gird[j][i]);
        if (gird[j][i] == '@') sx = j, sy = i;
    }
    dfs(sx, sy);
    printf("%d\n", cnt);
}

int main()
{
    while (~scanf("%d%d", &w, &h) && w && h)
        solve();
    return 0;
}