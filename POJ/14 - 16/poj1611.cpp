// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:   A
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

const int MaxN = 30005;
const int MaxM = 505;
struct DisjointSet
{
    int fa[MaxN], rk[MaxN];
    int tot[MaxN];
    /*
    other data set:
    */
    DisjointSet(int n)
    {
        fill(rk, rk + n, 0);
        fill(tot, tot + n, 1);
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
            //other method
            tot[y] += tot[x];
        }
        else
        {
            if (rk[x] == rk[y]) rk[x]++;
            fa[y] = x;
            //other method
            tot[x] += tot[y];
        }
    }
};

int n, m;

void solve()
{
    DisjointSet data(n);
    int tmp = 0, stu = 0, id = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tmp, &stu);
        for (int j = 1; j < tmp; j++)
        {
            scanf("%d", &id);
            data.Merge(stu, id);
        }
    }
    printf("%d\n", data.tot[data.fa[0]]);
}

int main()
{
    while (~scanf("%d%d", &n, &m) && n) solve();
    return 0;
}
