// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   I
******************************************************************************/

#pragma GCC optimize ("O2")
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
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

const int MaxN = 10240;
int fa[MaxN];

inline void init(int n) { n++; while (n--) fa[n] = n; }

inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }

inline bool Query(int x, int y) { return _find(x) == _find(y); }

inline void Merge(int x, int y) { fa[x] = y; }

struct package
{
    int px, dx;
    inline bool operator<(const package& b) const { return px > b.px; }
};

int n; bool vis[MaxN];
package a[MaxN];

void solve()
{
    int MaxT = 0;
    fill(vis, vis + n, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].px, &a[i].dx);
        updateMax(MaxT, a[i].dx);
    }
    init(MaxT + 1);
    sort(a, a + n);
    int ans = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        int d = _find(a[i].dx);
        if (d > 0) { ans += a[i].px; Merge(d, d - 1); }
    }
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}
