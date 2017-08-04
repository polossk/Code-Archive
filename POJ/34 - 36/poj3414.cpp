/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] D
#       @file         :D.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :BFS
******************************************************************************/

#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef pair<int, int> state;
int a, b, c;

bool vis[110][110];
int step[110][110], fa[110][110];
int method[110][110];

inline bool inbound(int x, int r, int l = 0)
{
    return x <= r && x >= 0;
}

inline int encode(int x, int y) { return x * 100 + y; }

inline state FILL_1(state past) { return make_pair(a, past.second); }

inline state FILL_2(state past) { return make_pair(past.first, b); }

inline state DROP_1(state past) { return make_pair(0, past.second); }

inline state DROP_2(state past) { return make_pair(past.first, 0); }

inline state POUR_1(state past)
{
    int pa = past.first, pb = past.second;
    int na = 0, nb = 0;
    int dt = pb + pa - b;
    if (dt > 0) na = dt, nb = b;
    else na = 0, nb = pa + pb;
    return make_pair(na, nb);
}

inline state POUR_2(state past)
{
    int pa = past.first, pb = past.second;
    int na = 0, nb = 0;
    int dt = pb + pa - a;
    if (dt > 0) nb = dt, na = a;
    else nb = 0, na = pa + pb;
    return make_pair(na, nb);
}

inline state newState(state p, int flag)
{
    switch (flag)
    {
    case 0: return FILL_1(p);
    case 1: return FILL_2(p);
    case 2: return DROP_1(p);
    case 3: return DROP_2(p);
    case 4: return POUR_1(p);
    case 5: return POUR_2(p);
    default: return p;
    }
}

void METHODPRINTER(int method)
{
    switch (method)
    {
    case 0: puts("FILL(1)"); return;
    case 1: puts("FILL(2)"); return;
    case 2: puts("DROP(1)"); return;
    case 3: puts("DROP(2)"); return;
    case 4: puts("POUR(1,2)"); return;
    case 5: puts("POUR(2,1)"); return;
    default: return;
    }
}

void path_Print(int x, int y)
{
    stack<int> dir;
    while (true)
    {
        int fx = fa[x][y] / 100;
        int fy = fa[x][y] % 100;
        if (fx == x && fy == y) break;
        dir.push(method[x][y]);
        x = fx; y = fy;
    }
    while (!dir.empty())
    {
        METHODPRINTER(dir.top());
        dir.pop();
    }
}

bool bfs(int& fx, int& fy)
{
    memset(method, 0, sizeof(method));
    memset(step, 0, sizeof(step));
    memset(vis, 0, sizeof(vis));
    memset(fa, 0, sizeof(fa));
    vis[0][0] = 1, fa[0][0] = 0;
    queue<state> q; q.push(make_pair(0, 0));
    while (!q.empty())
    {
        state top = q.front(); q.pop();
        int na = top.first, nb = top.second;
        if (na == c || nb == c)
        {
            fx = na, fy = nb;
            return 1;
        }
        for (int j = 0; j < 6; j++)
        {
            state tmp = newState(top, j);
            int xa = tmp.first, xb = tmp.second;
            if (inbound(xa, a) && inbound(xb, b) && !vis[xa][xb])
            {
                q.push(make_pair(xa, xb));
                vis[xa][xb] = 1;
                step[xa][xb] = step[na][nb] + 1;
                fa[xa][xb] = encode(na, nb);
                method[xa][xb] = j;
            }
        }
    }
    return 0;
}

void solve()
{
    int fx = 0, fy = 0;
    if (bfs(fx, fy))
    {
        printf("%d\n", step[fx][fy]);
        path_Print(fx, fy);
    }
    else puts("impossible");
}

int main()
{
    while (~scanf("%d%d%d", &a, &b, &c)) solve();
    return 0;
}
