// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 1000                                                 *
*****************************************************************************/

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
#include <limits>
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

const int maxN = 1010;
int x[maxN], y[maxN], z[maxN];
int n;

int gcd(int a, int b)
{
    return (b == 0)? a: gcd(b, a % b);
}

bool inbound(int x, int l, int r)
{
    if (l % x == 0 || r % x == 0 || r - l + 1 >= x)
        return 1;
    int tmpl = l / x, tmpr = r / x;
    if (tmpl != tmpr) return 1;
    else return 0;
}

bool test(int i, int j)
{
    int l = y[i] - z[j], r = z[i] - y[j];
    if (l > 0 || r < 0)
    {
        if (r < 0)
        {
            swap(i, j);
            l = y[i] - z[j], r = z[i] - y[j];
        }
        int d = gcd(x[i], x[j]);
        if (inbound(d, l, r))
            return 1;
        else return 0;
    }
    return 1;
}

void solve()
{
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
    bool success = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (test(i, j))
                { success = 0; break; }
    if (success)
        puts("Can Take off");
    else puts("Cannot Take off");
}

int main()
{
    while (cin >> n) solve();
    return 0;
}