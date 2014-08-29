/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :POJ 3669
#       @file         :G:\My Source Code\【ACM】训练\0702 - 搜索\poj3669.cpp
#       @date         :2014/07/02 15:07
#       @algorithm    :BFS
******************************************************************************/

#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

const int MaxN = 305;
const int MaxM = 50005;
const int dINF = 0x3f3f3f3f;
int m, res;
int dis[MaxN][MaxN];//alias of distance
int edg[MaxN][MaxN];//alias of endanger
//driection  u,  d,  r,  l,  s;
int dx[] = {-1,  1,  0,  0,  0};
int dy[] = { 0,  0,  1, -1,  0};

typedef pair<int, int> pnt;

inline bool check(int x, int y)
{
    return x >= 0 && y >= 0;
}

int bfs()
{
    if (edg[0][0] == 0) return -1;
    memset(dis, dINF, sizeof(dis)); dis[0][0] = 0;
    queue<pnt> q; q.push(make_pair(0, 0));
    while (!q.empty())
    {
        pnt frt = q.front();
        int x = frt.first, y = frt.second;
        if (edg[x][y] == dINF) break;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = dx[i] + x;
            int cy = dy[i] + y;
            if (check(cx, cy) && dis[x][y] + 1 < dis[cx][cy]
                            && dis[x][y] + 1 < edg[cx][cy])
            {
                dis[cx][cy] = dis[x][y] + 1;
                q.push(make_pair(cx, cy));
            }
        }
    }
    if (q.empty()) return -1;
    else
    {
        pnt ans = q.front();
        return dis[ans.first][ans.second];
    }
}

void solve()
{
    int t, x, y;
    memset(edg, dINF, sizeof(edg));
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &t);
        for (int j = 0; j < 5; j++)
        {
            int nx = x + dx[j], ny = y + dy[j];
            if (check(nx, ny)) updateMin(edg[nx][ny], t);
            else continue;
        }
    }
    res = bfs();
    printf("%d\n", res);
}

int main()
{
    while (~scanf("%d", &m)) solve();
    return 0;
}