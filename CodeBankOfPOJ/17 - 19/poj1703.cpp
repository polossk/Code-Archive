// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :
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

const int MaxN = 131072;
int fa[MaxN], r[MaxN];

inline void init(int n)
{
    fill(r, r + n, 0); n++;
    while (n--) fa[n] = n;
}

inline int _find(int x)
{
    if (fa[x] == x) return x;
    int t = fa[x];
    fa[x] = _find(fa[x]);
    r[x] = (r[x] + r[t]) % 2;
    return fa[x];
}

inline bool Query(int x, int y) { return _find(x) == _find(y); }

void Merge(int x, int y)
{
    int fx = _find(x), fy = _find(y);
    fa[fx] = fy; r[fx] = (1 + r[x] + r[y]) % 2;
}

int t, n, m;
const string Aye = "In the same gang.";
const string Nay = "In different gangs.";
const string Abs = "Not sure yet.";

void solve()
{
    scanf("%d%d", &n, &m);
    init(n + 1);
    char ch; int a, b;
    while (m--)
    {
        scanf(" %c%d%d", &ch, &a, &b);
        if (ch == 'A')
        {
            if (Query(a, b))
            {
                if (r[a] == r[b]) puts(Aye.c_str());
                else puts(Nay.c_str());
            }
            else puts(Abs.c_str());
        }
        else Merge(a, b);
    }
}

int main()
{
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
