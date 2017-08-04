// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:   B
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
struct DisjointSet
{
    int fa[MaxN];
    int und[MaxN], tot[MaxN];
    /*
    other data set:
    */
    DisjointSet(int n) { init(n); }
    inline void init(int n)
    {
        fill(und, und + n, 0);
        fill(tot, tot + n, 1);
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    inline int _find(int x)
    {
        if (fa[x] == x) return x;
        int f = _find(fa[x]);
        und[x] += und[fa[x]];
        fa[x] = f;
        return fa[x];
    }
    inline bool Query(int x, int y) { return _find(x) == _find(y); }
    void Merge(int x, int y)
    {
        x = _find(x); y = _find(y);
        if (x == y) return;
        fa[y] = x;
        //other method
        und[y] = tot[x];
        tot[x] += tot[y];
    }
};
DisjointSet data(30005);
int p; char ch;

void solve()
{
    data.init(30005);
    int a = 0, b = 0;
    for (int i = 0; i < p; i++)
    {
        scanf(" %c", &ch);
        if (ch == 'M')
        {
            scanf("%d%d", &a, &b);
            data.Merge(b, a);
        }
        else if (ch == 'C')
        {
            scanf("%d", &b);
            data._find(b);
            printf("%d\n", data.und[b]);
        }
        else continue;
    }
}

int main()
{
    while (~scanf("%d", &p)) solve();
    return 0;
}
