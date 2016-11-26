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
// #include <bits/stdc++.h>
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

const int MOD = 1000000003;
const int nn = 55;
const int MAXN = 65;
const int MAX_DIGIT = 30;

int64 er[MAXN], d[MAXN][MAXN], c[MAXN];
int m[MAXN];
int64 n, k;

void init()
{
	er[0] = 1;
	for (int i = 1; i <= MAX_DIGIT + 3; i++)
		er[i] = (er[i - 1] << 1);
}

int find(int _)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += bool(m[i] & er[_]);
	return ret;
}

int64 lowbit(int _, int r)
{
	if (r == 0) return 1;
	else return (_ & (er[r] - 1)) + 1;
}

int64 dp(int r, int top, int s, int t)
{
	if (s == 0)
	{
		if (top % 2 != t) return 0;
		else
		{
			if (r == 0) return 1;
			else return c[r - 1];
		}
	}
	d[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < top; j++)
		{
			d[i][j] = 0;
			if (m[i] & er[r])
			{
				if (i > s) d[i][j] = d[i - 1][j] * er[r] % MOD;
				if (i == s) d[i][j] = d[i - 1][j] % MOD;
			}
			else d[i][j] = d[i - 1][j] * lowbit(m[i], r) % MOD;
			if (m[i] & er[r])
			{
				if (i != s) d[i][j] += d[i - 1][j - 1] * lowbit(m[i], r);
			}
			d[i][j] %= MOD;
		}
	}
	int ret = 0;
	for (int i = 0; i < top; i++)
		ret = (i % 2 == t) ? (ret + d[n][i]) % MOD : ret;
	return ret;
}

int64 hoge()
{
	memset(c, 0, sizeof(c));
	for (int r = 0; r <= MAX_DIGIT; r++)
	{
		int top = find(r);
		int t = bool(k & er[r]);
		c[r] = 0;
		for (int i = 0; i <= n; i++)
			if (i == 0 || (m[i] & er[r]))
				c[r] = (c[r] + dp(r, top, i, t)) % MOD;
	}
	return c[MAX_DIGIT] % MOD;
}

int main()
{
	init();
	while (true)
	{
		n = nextInt();
		k = nextInt();
		if (n + k == 0) break;
		for (int i = 1; i <= n; i++) m[i] = nextInt();
		cout << hoge() << endl;
	}
	return 0;
}