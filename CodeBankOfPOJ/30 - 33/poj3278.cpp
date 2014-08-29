/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] A
#       @file         :A.cpp
#       @date         :2014/07/13 15:02
#       @algorithm    :BFS
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;
int n, k;
int step[100005];
bool vis[100005];
inline bool inbound(int x, int l = 0, int r = 100000) { return l <= x && x <= r; }

inline int newPos(int old, int method)
{
    if (method == 0) return old * 2;
    if (method == 1) return old + 1;
    if (method == 2) return old - 1;
}

int bfs(int beg, int tar)
{
    memset(step, 0, sizeof(step));
    memset(vis, 0, sizeof(vis));
    queue<int> q; q.push(beg); vis[beg] = 1;
    while (!q.empty())
    {
        int top = q.front(); q.pop();
        if (top == tar) break;
        for (int j = 0; j < 3; j++)
        {
            int tmp = newPos(top, j);
            if (inbound(tmp) && !vis[tmp])
            {
                vis[tmp] = 1; step[tmp] = step[top] + 1;
                q.push(tmp);
            }
        }
    }
    return step[tar];
}

int main()
{
    while (cin >> n >> k)
        printf("%d\n", bfs(n, k));
    return 0;
}
