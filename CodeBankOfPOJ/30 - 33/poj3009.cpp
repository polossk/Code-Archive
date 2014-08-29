/******************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] J
#       @file         :G:\My Source Code\¡¾ACM¡¿ÑµÁ·\0712 - [NWPU][2014][TRN][3]\J.cpp
#       @date         :2014/7/15 13:42
#       @algorithm    :DFS
******************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int64;
int w, h, res;
int gird[25][25];
//driection   u,  d,  r,  l;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

inline bool inbound(int l, int r, int x)
{
	return (x >= l && x < r);
}

inline bool check(int x, int y)
{
	return inbound(0, w, x) && inbound(0, h, y);
}

void dfs(int cnt, int x, int y)
{
	int cx = 0, cy = 0;
	bool flag = false;
	if (cnt > 10) return;
	for (int i = 0; i < 4; i++)
	{
		flag = false;
		if (gird[x + dx[i]][y + dy[i]] == 1)
			continue;
		cx = x, cy = y;
		while (1)
		{
			cx += dx[i], cy += dy[i];
			if (!check(cx, cy)) break;
			if (gird[cx][cy] == 1) { flag = true; break; }
			if (gird[cx][cy] == 3) { res = min(res, cnt); break; }
		}
		if (flag)
		{
			gird[cx][cy] = 0;
			dfs(cnt + 1, cx - dx[i], cy - dy[i]);
			gird[cx][cy] = 1;
		}
	}
}

void solve()
{
	memset(gird, 0, sizeof(gird));
	res = 11;
	int sx = 0, sy = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			scanf(" %d", &gird[j][i]);
			if (gird[j][i] == 2) sx = j, sy = i;
		}
	dfs(1, sx, sy);
	if (res > 10)   printf("-1\n");
	else            printf("%d\n", res);
}

int main()
{
	while (scanf("%d%d", &w, &h))
	{
		if (w == 0 && h == 0) break;
		else solve();
	}
	return 0;
}