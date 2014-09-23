// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4447                                                 *
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

const int MaxN = 1420;
struct poly
{
    int n, value[MaxN];

    inline bool operator<(const poly& b) const
    {
        if (n == b.n)
        {
            for (int i = n; i >= 0; i--)
            {
                if (abs(value[i]) == abs(b.value[i]))
                {
                    if (value[i] != b.value[i])
                        return value[i] < b.value[i];
                }
                else
                    return abs(value[i]) < abs(b.value[i]);
            }
        }
        else return n < b.n;
    }

    void __print(int p, int v, bool isFirst)
    {
        // print polynomial v * x ^ p
        if (v == 0) return;
        if (!isFirst)
        {
            if (v > 0) putchar('+');
            else putchar('-');
        }
        if (p == 0) { putchar('1'); return; }
        else
        {
            if (v != 1 && v != -1) printf("%d", abs(v));
            putchar('x');
            if (p > 1) printf("^%d", p);
        }
    }

    void print()
    {
        putchar('(');
        __print(n, value[n], true);
        for (int i = n - 1; i >= 0; i--)
            __print(i, value[i], false);
        putchar(')');
    }
};

poly operator/(poly a, const poly& b)
{
    poly c; c.n = a.n - b.n;
    for (int i = c.n; i >= 0; i--)
    {
        if (a.n - b.n < i) { c.value[i] = 0; continue; }
        c.value[i] = a.value[a.n] / b.value[b.n];
        int d = a.n - b.n; a.n = a.n - b.n;
        for (int j = b.n; j >= 0; j--)
        {
            a.value[j + d] -= b.value[j] * c.value[i];
            if (a.value[j + d]) updateMax(a.n, j + d);
        }
    }
    return c;
}

poly phi[MaxN], res[MaxN];
bool vis[MaxN];
int n, tot;

void factor(int n)
{
    tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                phi[i].n = i;
                phi[i].value[i] = 1;
                phi[i].value[0] = -1;
                for (int j = 1; j < i; j++)
                    if (i % j == 0)
                        phi[i] = phi[i] / phi[j];
            }
            res[tot++] = phi[i];
        }
    }
    sort(res, res + tot);
}

void solve()
{
    if (n == 1) { printf("x-1\n"); return; }
    else
    {
        factor(n);
        for (int i = 0; i < tot; i++)
            res[i].print();
        puts("");
    }
}

int main()
{
    fill(vis, vis + MaxN, false);
    while (~scanf("%d", &n) && n) solve();
    return 0;
}