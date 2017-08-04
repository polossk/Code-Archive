/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] L
* @file         :G:\My Source Code\【ACM】训练\[NWPU][2014][TRN][6][0716]简单线性dp\L.cpp
* @date         :2014/07/16 11:59
* @algorithm    :Greedy
******************************************************************************/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

const int MaxN = 405;
int t, n, from, to;
int room[MaxN];

//  room[i]表示从房间i经过的次数
//  ans = max{room[i]} * 10;

void solve()
{
	scanf("%d", &n);
	memset(room, 0, sizeof(room));
	while (n--)
	{
		scanf("%d%d", &from, &to);
		if (to % 2) to++;
		if (from % 2) from++;
		if (from > to) swap(from, to);
		for (int i = from; i <= to; i += 2) room[i]++;
	}
	int ans = room[0];
	for (int i = 1; i < MaxN; i++) updateMax(ans, room[i]);
	printf("%d0\n", ans);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
