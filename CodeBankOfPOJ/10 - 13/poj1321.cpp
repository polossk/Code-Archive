/******************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] K
#       @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\0712 - [NWPU][2014][TRN][3]\K.cpp
#       @date         :2014/7/15 13:46
#       @algorithm    :DFS
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

const int MaxL = 13;
int cnt, n, k;
char grid[MaxL][MaxL];
bool vis[MaxL];

void dfs(int x, int cur)
{
	if (cur == k) { cnt++; return; }
	else
	{
		for (int i = x; i < n; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == '#' && !vis[j])
				{
					vis[j] = 1;
					dfs(i + 1, cur + 1);
					vis[j] = 0;
				}
	}
}

void solve()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &grid[i][j]);
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	dfs(0, 0);
	printf("%d\n", cnt);
}

int main()
{
	while (scanf("%d%d", &n, &k))
	{
		if (n == -1 && k == -1) break;
		else solve();
	}
	return 0;
}