/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] G
#       @file         :G.cpp
#       @date         :2014/07/14 17:41
#       @algorithm    :DFS
******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

int t, tt, a, b;
int vis[27][27];
pair<int, int> path[27];
bool flag = 0;

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }

inline int encode(int x, int y) { return a * x + y; }

void dfs(int x, int y, int n)
{
	if (!flag && vis[x][y] == 0
		&& inbound(x, 0, a) && inbound(y, 0, b)
		&& n <= a * b)
	{
		vis[x][y] = n;
        path[n] = make_pair(x, y);
		n++;
		if (n > a * b) flag = 1;
		dfs(x - 2, y - 1, n);
		dfs(x - 2, y + 1, n);
		dfs(x - 1, y - 2, n);
		dfs(x - 1, y + 2, n);
		dfs(x + 1, y - 2, n);
		dfs(x + 1, y + 2, n);
		dfs(x + 2, y - 1, n);
		dfs(x + 2, y + 1, n);
		vis[x][y] = 0;
	}
	else return;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &b, &a);
        memset(vis, 0, sizeof(vis));
        printf("Scenario #%d:\n", ++tt);
        flag = 0; dfs(0, 0, 1);
        if (flag)
        {
            for (int i = 1; i <= a * b; i++)
                printf("%c%d", 'A' + path[i].first, path[i].second + 1);
            puts("");
        }
        else puts("impossible");
        if (t != 0) puts("");
    }
	return 0;
}
