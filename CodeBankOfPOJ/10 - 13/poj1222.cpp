// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 1222                                                 *
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

const int MaxN = 40;
int a[MaxN][MaxN];
int x[MaxN];
int equ, var;

//
//
int Gauss()
{
	int i, j, k;
	int max_r;
	int col;
	int temp;

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
			for (j = col; j < var + 1; j++)
				a[i][j] ^= a[k][j];
		}
	}
	for (i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for (j = i + 1; j < var; j++)
            x[i] ^= (a[i][j] && x[j]);
    }
	return 0;
}

void build()
{
    memset(a, 0, sizeof(a));
    equ = var = 30;
    for (int i = 0; i < 5; i++) for (int j = 0; j < 6; j++)
    {
        int t = i * 6 + j;
        a[t][t] = 1;
        if (i > 0) a[(i - 1) * 6 + j][t] = 1;
        if (i < 4) a[(i + 1) * 6 + j][t] = 1;
        if (j > 0) a[i * 6 + (j - 1)][t] = 1;
        if (j < 5) a[i * 6 + (j + 1)][t] = 1;
    }
}

int tt = 0;

void solve()
{
	build();
    for (int i = 0; i < 30; i++) a[i][30] = nextInt();
    Gauss();
    printf("PUZZLE #%d\n", ++tt);
    for (int i = 0; i < 30; i++)
    {
        if (i % 6 == 0) printf("%d", x[i]);
        else if (i % 6 == 5) printf(" %d\n", x[i]);
        else printf(" %d", x[i]);
    }
}

int main()
{
	int t = nextInt();
	while (t--) solve();
    return 0;
}
