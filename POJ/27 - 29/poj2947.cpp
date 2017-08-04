// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2947                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
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

const int MaxN = 405;
int a[MaxN][MaxN];
int x[MaxN];
bool free_x[MaxN];

inline int __m(int value, int MOD = 7)
{
	return (value % MOD + MOD) % MOD;
}

inline int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

inline int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int64 mul_mod(int64 a, int64 b, int64 m)
{
    int64 t = 0; a %= m; b %= m;
    while (b)
    {
        if (b & 1) t += a, t %= m;
        a <<= 1; a %= m; b >>= 1;
    }
    return t;
}

int64 pow_mod(int64 a, int64 b, int64 m)
{
    int64 ans = 1; a %= m;
    while (b)
    {
        if (b & 1) { ans = mul_mod(ans, a, m); b--; }
        b >>= 1; a = mul_mod(a, a, m);
    }
    return ans;
}

//
//
int Gauss(int equ, int var, int MOD = 7)
{
	int i, j, k;
	int max_r;
	int col;
	int ta, tb, LCM;
	int temp;
	int free_x_num;
	int free_index;

	for (int i = 0; i <= var; i++)
	{
		x[i] = 0;
		free_x[i] = true;
	}
	col = 0;
	for (k = 0; k < equ && col < var; k++, col++)
	{
		max_r = k;
		for (i = k + 1; i < equ; i++)
			max_r = abs(a[i][col]) > abs(a[max_r][col])? i: max_r;

		if (max_r != k) for (j = k; j < var + 1; j++)
			swap(a[k][j], a[max_r][j]);
		if (a[k][col] == 0) { k--; continue; }
		for (i = k + 1; i < equ; i++) if (a[i][col] != 0)
		{
			LCM = lcm(abs(a[i][col]), abs(a[k][col]));
			ta = LCM / abs(a[i][col]);
			tb = LCM / abs(a[k][col]);
			if (a[i][col] * a[k][col] < 0) tb = -tb;
			for (j = col; j < var + 1; j++)
				a[i][j] = __m(a[i][j] * ta - a[k][j] * tb, MOD);
		}
	}
	for (i = k; i < equ; i++) if (a[i][col] != 0)
		return -1;
	if (k < var)
	{
		for (i = k - 1; i >= 0; i--)
		{
			free_x_num = 0;
			for (j = 0; j < var; j++) if (a[i][j] != 0 && free_x[j])
				free_x_num++, free_index = j;
			if (free_x_num > 1) continue;
			temp = a[i][var];
			for (j = 0; j < var; j++)
			{
				if (a[i][j] != 0 && j != free_index)
					temp -= a[i][j] * x[j] % MOD;
				temp = __m(temp, MOD);
			}
			while (temp % a[i][free_index] != 0) temp += MOD;
			x[free_index] = (temp / a[i][free_index]) % MOD;
		}
		return var - k;
	}
	for (i = var - 1; i >= 0; i--)
	{
		temp = a[i][var];
		for (j = i + 1; j < var; j++)
		{
			temp -= (a[i][j] != 0)? a[i][j] * x[j]: 0;
			temp = __m(temp, MOD);
		}
		while (temp % a[i][i] != 0) temp += MOD;
		x[i] = __m(temp / a[i][i]);
	}
	return 0;
}

int tran(char *s)
{
    if (strcmp(s, "MON") == 0) return 1;
    else if (strcmp(s, "TUE") == 0) return 2;
    else if (strcmp(s, "WED") == 0) return 3;
    else if (strcmp(s, "THU") == 0) return 4;
    else if (strcmp(s, "FRI") == 0) return 5;
    else if (strcmp(s, "SAT") == 0) return 6;
    else return 7;
}

char str1[20];
char str2[20];
int n,  m, k, t;

void solve()
{
	memset(a, 0, sizeof(a));
    for (int i = 0; i < m; i++)
    {
        scanf("%d%s%s", &k, &str1, &str2);
        a[i][n] = __m(tran(str2) - tran(str1) + 1);
        while (k--)
        {
            t = nextInt() - 1;
            a[i][t]++;
            a[i][t] %= 7;
        }
    }
    int ans = Gauss(m, n);
    if (ans == 0)
    {
        for (int i = 0; i < n; i++)
            x[i] += (x[i] <= 2) ? 7 : 0;
        for (int i = 0; i < n - 1; i++)
            printf("%d ", x[i]);
        printf("%d\n", x[n - 1]);
    }
    else if (ans == -1) puts("Inconsistent data.");
    else puts("Multiple solutions.");
}

int main()
{
	while (~scanf("%d%d", &n, &m) && (n && m)) solve();
    return 0;
}