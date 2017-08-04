// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 3814                                                 *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int INF = 0x3f3f3f3f;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int oppd[4] = {2, 3, 0, 1};

char s1[50][50], s2[50][50];
int test, id[4][4], isOK[10][5];
int good[10][5];
char sa[9][9], sb[9][9];
int dis[1 << 20], q[1 << 20];

void rotate(char a[9][9])
{
	int temp[9][9];
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			temp[i][j] = a[i][j];
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			a[j][8 - i + 1] = temp[i][j];
}

int checkSame()
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			if (sa[i][j] != sb[i][j])
				return 0;
	return 1;
}

int get(int v[4][4], int sx, int sy)
{
	int temp[4][4], qx[16] = {0}, qy[16] = {0};
	int will[4][4] = {0}, ret = 0;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			temp[i][j] = v[i][j];
	qx[1] = sx, qy[1] = sy;
	for (int h = 1, t = 1; h <= t; h++)
	{
		int x = qx[h], y = qy[h];
		will[x][y] = 1;
		for (int d = 0; d < 4; d++)
		{
			int xx = x + dx[d], yy = y + dy[d];
			if (xx < 1 || xx > 3 || yy < 1 || yy > 3 || will[xx][yy] == 1)
				continue;
			int od = oppd[d];
			if (good[id[x][y]][(d - v[x][y] + 4) % 4]
			&& good[id[xx][yy]][(od - v[xx][yy] + 4) % 4])
			{
				will[xx][yy] = 1;
				qx[++t] = xx, qy[t] = yy;
			}
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (will[i][j])
			{
				if ((i + j) % 2 == (sx + sy) % 2)
					v[i][j] = (v[i][j] + 1) % 4;
				else
					v[i][j] = (v[i][j] + 3) % 4;
			}
			ret <<= 2;
			ret |= v[i][j];
			v[i][j] = temp[i][j];
		}
	}
	
	return ret;
}

void solve()
{
	for (int i = 1; i <= 24; i++)
	{
		scanf("%s", s1[i] + 1);
		scanf("%s", s1[i] + 9);
		scanf("%s", s1[i] + 17);
	}
	for (int i = 1; i <= 24; i++)
	{
		scanf("%s", s2[i] + 1);
		scanf("%s", s2[i] + 9);
		scanf("%s", s2[i] + 17);
	}
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j < 4; j++)
			good[i][j] = nextInt();
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 8; k++)
			{
				for (int l = 1; l <= 8; l++)
				{
					sa[k][l] = s1[(i - 1) * 8 + k][(j - 1) * 8 + l];
					sb[k][l] = s2[(i - 1) * 8 + k][(j - 1) * 8 + l];
				}
			}
			for (int k = 0; k < 4; k++) 
			{
				isOK[id[i][j]][k] = checkSame();
				rotate(sa);
			}
		}
	}
	int full = (1 << 18) - 1;
	for (int i = 0; i <= full; i++) dis[i] = INF;
	dis[0] = 0;
	q[1] = 0;
	for (int h = 1, t = 1; h <= t; h++)
	{
		int now = q[h], disNow = dis[now], tag = 1;
		int v[4][4];
		for (int i = 3; i >= 1; i--)
		{
			for (int j = 3; j >= 1; j--)
			{
				v[i][j] = now & 3;
				tag &= isOK[id[i][j]][v[i][j]];
				now >>= 2;
			}
		}
		if (tag) { printf("%d\n", disNow); return; }
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				int x = get(v, i, j);
				if (disNow + 1 < dis[x])
				{
					dis[x] = disNow + 1;
					q[++t] = x;
				}
			}
		}
	}
	printf("%d\n", -1);
}

int main()
{
	int tot = 0;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			id[i][j] = ++tot;
	test = nextInt();
	while (test--) solve();
	return 0;
}