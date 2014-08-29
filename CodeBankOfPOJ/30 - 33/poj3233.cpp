#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 128;

struct Matrax { int m[MaxN][MaxN]; };

int n, k, M;
Matrax a, unit;


void init()
{
	int i, j;
	memset(a.m, 0, sizeof(a.m));
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		scanf("%d", &a.m[i][j]);
		a.m[i][j] %= M;
		unit.m[i][j] = (i == j);
	}
}

Matrax operator+(const Matrax& a, const Matrax& b)
{
	Matrax c;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		c.m[i][j] = (a.m[i][j] + b.m[i][j]) % M;
	return c;
}

Matrax operator*(const Matrax& a, const Matrax& b)
{
	Matrax c;
	int k, i, j;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		c.m[i][j] = 0;
		for (int k = 0; k < n; k++)
			c.m[i][j] += a.m[i][k] * b.m[k][j];
		c.m[i][j] %= M;
	}
	return c;
}

Matrax operator^(const Matrax& a, int k)
{
	Matrax p = a, ans = unit;
	while (k)
	{
		if (k & 1) { ans = ans * p; k--; }
		else { k /= 2; p = p * p; }
	}
	return ans;
}

Matrax MatraxSum(const Matrax& a, int k)
{
	if (k == 1) return a;
	Matrax tmp, b;
	tmp = MatraxSum(a, k / 2);
	if (k & 1)
	{
		b = a ^ (k / 2 + 1);
		tmp = tmp + (tmp * b);
		tmp = tmp + b;
	}
	else
	{
		b = a ^ (k / 2);
		tmp = tmp + (tmp * b);
	}
	return tmp;
}

int main()
{
	while (~scanf("%d%d%d", &n, &k, &M))
	{
		init();
		Matrax ans = MatraxSum(a, k);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
				printf("%d ", ans.m[i][j]);
			printf("%d\n", ans.m[i][n - 1]);
		}
	}
	return 0;
}
