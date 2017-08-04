/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRN][3] I
#       @file         :I.cpp
#       @date         :2014/07/15 12:10
#       @algorithm    :DFS
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int MaxL = 1005;
int num[MaxL], ans[MaxL];
bool flag;
int vis, step, m, n;

void dfs(int x, int cnt)
{
	if (cnt > n) return;
	else if (cnt == n)
	{
		flag = true;
		printf("%d", ans[1]);
		for (int i = 2; i < step; i++)
			printf("+%d", ans[i]);
		puts(""); return;
	}
	int vis = -1;
	for (int j = x + 1; j <= m; j++)
	{
		if (num[j] != vis)
		{
			ans[step++] = num[j];
			vis = num[j];
			dfs(j, cnt + num[j]);
			step--;
		}
	}
}

void solve()
{
	flag = false;
	step = 1;
	memset(num, 0, sizeof(num));
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= m; i++)
		scanf("%d", &num[i]);
	printf("Sums of %d:\n", n);
	dfs(0, 0);
	if (!flag) printf("NONE\n");
}

int main()
{
    while(~scanf("%d%d", &n, &m) && m && n)
        solve();
    return 0;
}
