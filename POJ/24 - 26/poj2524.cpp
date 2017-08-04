// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:	E
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

const int MaxN = 50003;
int fa[MaxN], rk[MaxN];

inline void init(int n)
{
    fill(rk, rk + n, 0); n++;
    //for (int i = 0; i < n; i++) fa[i] = i;
    while (n--) fa[n] = n;
}

inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }

inline bool Query(int x, int y) { return _find(x) == _find(y); }

void Merge(int x, int y)
{
    x = _find(x); y = _find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) fa[x] = y;
    else { fa[y] = x; rk[x] += (rk[x] == rk[y]); }
}

int n, m, tt, a, b;

void solve()
{
    init(n + 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        a = _find(a); b = _find(b);
        if (a != b) { n--; Merge(a, b); }
    }
    printf("Case %d: %d\n", ++tt, n);
}

int main()
{
    while (~scanf("%d%d", &n, &m) && n && m) solve();
    return 0;
}
