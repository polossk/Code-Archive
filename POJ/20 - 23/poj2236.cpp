// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   H
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

const int MaxN = 1024;
int fa[MaxN], rk[MaxN];

inline void init(int n)
{
    fill(rk, rk + n, 0); n++;
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

typedef pair<int, int> Point;
bool grid[MaxN][MaxN], vis[MaxN];
Point data[MaxN];
int n, d;
const string s = "SUCCESS";
const string f = "FAIL";

inline double dis(Point& a, Point& b)
{
    double dx = double(a.first - b.first);
    double dy = double(a.second - b.second);
    double ds = dx * dx + dy * dy;
    return sqrt(ds);
}

inline bool judge(Point& a, Point& b)
{
    static double d0 = double(d);
    double ds = dis(a, b);
    return ds <= d0;
}

void solve()
{
    init(n + 1);
    char ch = 0; int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &data[i].first, &data[i].second);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            grid[i][j] = grid[j][i] = judge(data[i], data[j]);

    while (~scanf(" %c", &ch))
    {
        if (ch == 'S')
        {
            scanf("%d%d", &a, &b);
            if (Query(a, b)) puts(s.c_str());
            else puts(f.c_str());
        }
        else if (ch == 'O')
        {
            scanf("%d", &a);
            for (int i = 1; i <= n; i++)
                if (vis[i] && grid[a][i])
                    Merge(a, i);
            vis[a] = 1;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &d);
    solve();
    return 0;
}
