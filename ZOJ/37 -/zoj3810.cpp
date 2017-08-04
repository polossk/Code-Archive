// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 3810                                                 *
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

const int MaxN = 128;
int n;
char grid[MaxN][MaxN], col[2] = {'G', 'R'};

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%c", grid[i][j]);
		puts("");
	}
}

void color()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grid[i][j] = 'B';
	for (int i = 0; i < n; i++)
		grid[0][i] = 'Y';
	for (int i = 0; i < (n - 1) / 2; i++)
	{
		char c = col[i % 2];
		for (int j = i + 1; j < n; j++) grid[j][i] = c;
		for (int j = 1; j <= i + 1; j++) grid[j][i + 1] = c;
	}
	for (int i = (n - 1) / 2; i < n - 1; i++)
	{
		char c = col[i % 2];
		for (int j = i + 2; j <n; j++) grid[j][i] = c;
		grid[i + 2][i + 1] = c;
		for (int j = 2; j <= i + 2; j++) grid[j][i + 2] = c;
	}
}

void solve()
{
	n = nextInt();
	if (n == 1) puts("Y");
	else if (n <= 4) puts("No solution!");
	else if (n == 6)
	{
		puts("YYYYYY");
		puts("GGRGRR");
		puts("GRRGRB");
		puts("GRGGRB");
		puts("GRGRRB");
		puts("GRGBBB");
	}
	else { color(); print(); }
}

int main()
{
	int t = nextInt();
	while (t--) solve();
    return 0;
}
