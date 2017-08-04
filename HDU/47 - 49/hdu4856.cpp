/****
	*@author    Shen
	*@title     西安邀请赛J
	*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxN = 25;
const int maxM = 21;
const int inf  = 500000000;
int n, m, tot, a[maxN * maxN][maxN * maxN];
int cost[maxM][maxM], f[maxM][1 << maxM];
bool bar[maxN][maxN];
char str[maxN];
pair <int, int> tunnel[maxM];

inline int encode(int x, int y)
{
	return (x - 1) * n + y;
}

void DataScanner()
{
	for (int i = 1; i <= n; i++) bar[i][i] = false;
	tot = n * n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= n; j++)
		{
			if (str[j]=='#') bar[i][j] = true;
			else bar[i][j] = false;
		}
	}
	int x1, x2, y1, y2;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d",  &x1,  &y1,  &x2,  &y2);
		tunnel[i] = make_pair(encode(x1, y1), encode(x2, y2));
	}
}

void Build()
{
    for (int i = 1; i <= tot; i++)
		for (int j = 1; j <= tot; j++)
			a[i][j] = inf;
	for (int i = 1; i <= tot; i++)
		a[i][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (bar[i][j]) continue;
			if (j < n && !bar[i][j + 1])
                a[encode(i, j)][encode(i, j + 1)] = a[encode(i, j + 1)][encode(i, j)] = 1;
			if (i < n && !bar[i + 1][j])
                a[encode(i, j)][encode(i + 1, j)] = a[encode(i + 1, j)][encode(i, j)] = 1;
		}
	}
}

void Floyd()
{
	for (int k = 1; k <= tot; k++)
		for (int i = 1; i <= tot; i++)
			for (int j = 1; j <= tot; j++)
				a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
}

void DP()
{
	for (int i = 1; i <= m; i++)
		for (int j = 1;j <= m;j++)
			if (i == j) continue;
			else
                cost[i][j] = a[tunnel[i].second][tunnel[j].first];
	for (int i = 1; i <= m; i++)
		for (int j = 0; j<(1 << m); j++)
			f[i][j] = inf;
	for (int i = 1; i <= m; i++)
		f[i][1 << (i-1)] = 0;
	for (int mask = 0; mask < (1 << m); mask++)
	{
		for (int i = 1; i <= m; i++)
		{
			if (!(mask & (1 << (i - 1)))) continue;
			for (int j = 1;j <= m;j++)
			{
				if (mask & (1 << (j - 1))) continue;
				f[j][mask ^ (1 << (j - 1))] = min(f[j][mask ^ (1 << (j - 1))], f[i][mask] + cost[i][j]);
			}
		}
	}
	int ans = f[1][(1 << m)-1];
	for (int i = 2; i <= m; i++) ans = min(ans, f[i][(1 << m)-1]);
	if (ans >= inf) printf("-1\n");
	else printf("%d\n", ans);
}

void solve()
{
    DataScanner();
    Build();
    Floyd();
    DP();
}

int main()
{
	while (~scanf("%d%d", &n, &m))
        solve();
	return 0;
}
