/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] C
#       @file         :C.cpp
#       @date         :2014/07/13 15:13
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
int step[8][8], fa[8][8];
bool vis[8][8];

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }

inline bool inbound(int u)
{
    int x = u / 8, y = u % 8;
    return inbound(x, 0, 8) && inbound(y, 0, 8);
}

inline int encode(int x, int y) { return x * 8 + y; }

inline int newPos(int old, int method)
{
    int x = old / 8, y = old % 8;
    x += dx[method], y += dy[method];
    if (inbound(x, 0, 8) && inbound(y, 0, 8)) return encode(x, y);
    else return -1;
}

inline int getx(string s) { return int(s[0] - 'a'); }

inline int gety(string s) { return int(s[1] - '1'); }

int bfs(string _beg, string _tar)
{
    int beg = encode(getx(_beg), gety(_beg));
    int tar = encode(getx(_tar), gety(_tar));
    memset(step, 0, sizeof(step));
    memset(vis, 0, sizeof(vis));
    memset(fa, 0, sizeof(fa));
    queue<int> q; q.push(beg); vis[beg / 8][beg % 8] = 1;
    fa[beg / 8][beg % 8] = beg;
    while (!q.empty())
    {
        //bprint();
        int top = q.front(); q.pop();
        if (top == tar) break;
        for (int j = 0; j < 8; j++)
        {
            int tmp = newPos(top, j);
            if (tmp != -1 && inbound(tmp) && !vis[tmp / 8][tmp % 8])
            {
                vis[tmp / 8][tmp % 8] = 1;
                step[tmp / 8][tmp % 8] = step[top / 8][top % 8] + 1;
                fa[tmp / 8][tmp % 8] = top;
                q.push(tmp);
            }
        }
    }
    return step[tar / 8][tar % 8];
}

int main()
{
    string b, t;
    while (cin >> b >> t)
        printf("To get from %s to %s takes %d knight moves.\n", b.c_str(), t.c_str(), bfs(b, t));
    return 0;
}
