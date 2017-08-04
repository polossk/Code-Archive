#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long int64;

const int MaxN = 128;
struct Matrax
{
	int64 m[MaxN][MaxN];
	Matrax() { memset(m, 0, sizeof(m)); }
};

Matrax coef, ans;
int n, M, K;

Matrax operator*(const Matrax& a, const Matrax& b)
{
	Matrax c;
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++)
	{
		if (a.m[i][j]) for (int k = 0; k <= n; k++)
			c.m[i][k] += a.m[i][j] * b.m[j][k];
	}
	return c;
}

Matrax operator^(const Matrax& a, int k)
{
	Matrax p = a, ans;
	for (int i = 0; i <= n; i++) ans.m[i][i] = 1;
	while (k)
	{
		if (k & 1) { ans = ans * p; k--; }
		else { k /= 2; p = p * p; }
	}
	return ans;
}

void init()
{
	int x, y; int64 t; char w[2];
	memset(coef.m, 0, sizeof(coef.m));
	for (int i = 0; i <= n; i++) coef.m[i][i] = 1;
	while (K--)
	{
		cin >> w;
		if (w[0] == 'g')
		{
			cin >> x; x--;
			coef.m[n][x]++;
		}
		else if( w[0] == 's')
		{
			cin >> x >> y; x--; y--;
			if (x != y) for (int i = 0; i <= n; i++)
				swap(coef.m[i][x], coef.m[i][y]);
		}
		else
		{
			cin >> x; x--;
			for (int i = 0; i <= n; i++) coef.m[i][x] = 0;
		}
	}
}

int main()
{
	while (cin >> n >> M >> K)
	{
		if (n == 0 && M == 0 && K == 0) return 0;
		init();
		ans = coef ^ M;
		int i;
		for (int i = 0; i < n; i++) cout << ans.m[n][i] << " ";
		puts("");
	}
	return 0;
}
