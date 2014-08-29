// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   C
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

const int MaxN = 50005 * 3;
struct DisjointSet
{
    int fa[MaxN * 3], rk[MaxN * 3];
    DisjointSet(int n) { init(n); }
    inline void init(int n)
    {
        fill(rk, rk + n, 0);
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    inline int _find(int x) { return fa[x] = (fa[x] == x)? x: _find(fa[x]); }
    inline bool Query(int x, int y) { return _find(x) == _find(y); }
    void Merge(int x, int y)
    {
        x = _find(x); y = _find(y);
        if (x == y) return;
        if (rk[x] < rk[y])
        {
            fa[x] = y;
        }
        else
        {
            if (rk[x] == rk[y]) rk[x]++;
            fa[y] = x;
        }
    }
};
DisjointSet data(MaxN * 3);

int n, k;

void solve()
{
    int ans = 0;
    data.init(n * 3);
    for (int i = 0; i < k; i++)
    {
        int t = 0, x = 0, y = 0;
        scanf("%d%d%d", &t, &x, &y);
        x -= 1; y -= 1;
        if (x < 0 || x >= n || y < 0 || y >= n) { ans++; continue; }
        if (t == 1)
        {
            if (data.Query(x, y + n) || data.Query(x, y + n * 2)) ans++;
            else
            {
                data.Merge(x, y);
                data.Merge(x + n, y + n);
                data.Merge(x + n * 2, y + n * 2);
            }
        }
        else
        {
            if (data.Query(x, y) || data.Query(x, y + n * 2)) ans++;
            else
            {
                data.Merge(x, y + n);
                data.Merge(x + n, y + n * 2);
                data.Merge(x + n * 2, y);
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &n, &k); solve();
    return 0;
}
