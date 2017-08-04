// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:   D
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

const int MaxN = 2048;
const int MaxK = 1000005;
int t, tt;
int n, k;

int fa[MaxN], rk[MaxN];
int a[MaxN];
inline void init(int n)
{
    fill(rk, rk + n, 0);
    fill(a, a + n, 0);
    for (int i = 0; i < n; i++) fa[i] = i;
}
inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }
inline bool Query(int x, int y) { return _find(x) == _find(y); }
void Merge(int x, int y)
{
    x = _find(x); y = _find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) fa[x] = y;
    else
    {
        fa[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
    }
}

void solve()
{
    scanf("%d%d", &n, &k);
    init(n + 10);
    bool res = 0; int x = 0, y = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &x, &y);
        if (res) continue;
        if (Query(x, y)) res = 1;
        if (a[x] == 0 && a[y] == 0) { a[x] = y; a[y] = x; }
        else if (a[x] == 0) { a[x] = y; Merge(x, a[y]); }
        else if (a[y] == 0) { a[y] = x; Merge(y, a[x]); }
        else { Merge(x, a[y]); Merge(y, a[x]); }
    }
    printf("Scenario #%d:\n", ++tt);
    if (res) puts("Suspicious bugs found!\n");
    else puts("No suspicious bugs found!\n");
}

int main()
{
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
