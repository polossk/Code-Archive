// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:	F
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

const int MaxN = 1024;
const int MaxM = 16384;
int fa[MaxN], rk[MaxN];

inline void init(int n) {  fill(rk, rk + n, 0); n++; while (n--) fa[n] = n; }

inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }

inline bool Query(int x, int y) { return _find(x) == _find(y); }

void Merge(int x, int y)
{
    x = _find(x); y = _find(y);
    if (x == y) return;
    if (rk[x] < rk[y]) fa[x] = y;
    else { fa[y] = x; rk[x] += (rk[x] == rk[y]); }
}

struct Edge
{
    int u, v, w;
    inline bool operator<(const Edge& b) const { return w < b.w; }
};

Edge e[MaxM];
int n, m, k, l, r[MaxN];

void solve()
{
    init(n + 1); l = k = 0;
    fill(r, r + n, 0);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e, e + m);
    for (int i = 0; i < m; i++)
    {
        int a = _find(e[i].u);
        int b = _find(e[i].v);
        if (a != b)
        {
            updateMax(l, e[i].w);
            r[k++] = i;
            Merge(a, b);
        }
    }
    printf("%d\n%d\n", l, k);
    for (int i = 0; i < k; i++)
        printf("%d %d\n", e[r[i]].u, e[r[i]].v);
}

int main()
{
    while (~scanf("%d%d", &n, &m) && n && m) solve();
    return 0;
}
