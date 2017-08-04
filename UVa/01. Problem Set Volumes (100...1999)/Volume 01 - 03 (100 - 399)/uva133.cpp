// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 133                                                  *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

const int MaxN = 32;

int q[MaxN];
int n, k, m, l;

void reset()
{
    fill(q, q + MaxN, 0);
    l = n;
    for (int i = 0; i <= n; i++)
        q[i] = i;
}

int select(int c1, int c2, int& x1, int& x2)
{
    x1 = x2 = 0;
    int j = 0;
    for (int i = c1, j = 0; j < k; i++)
    {
        i -= i > n? n: 0;
        int pos = i;
        j += (q[pos] != 0);
        x1 = (j == k)? pos: 0;
    }
    for (int i = c2, j = 0; j < m; i--)
    {
        i += (i < 1)? n: 0;
        int pos = i;
        j += (q[pos] != 0);
        //printf("%d: at pos = %d.\n", j, pos);
        x2 = (j == m)? pos: 0;
    }
    q[x1] = q[x2] = 0;
    if (x1 == x2) return 1;
    else return 2;
}

void solve()
{
    reset();
    bool flag = 0;
    int c1 = 1, c2 = n, x1 = 0, x2 = 0;
    while (l)
    {
        int num = select(c1, c2, x1, x2);
        l -= num;
        c1 = x1 + 1; c1 = c1 > n? c1 - n: c1;
        c2 = x2 - 1; c2 = c2 < 1? c2 + n: c2;
        if (flag)
        {
            if (num == 1) printf(",%3d", x1);
            else printf(",%3d%3d", x1, x2);
        }
        else
        {
            flag = 1;
            if (num == 1) printf("%3d", x1);
            else printf("%3d%3d", x1, x2);
        }
        //system("pause");
    }
    puts("");
}

int main()
{
    while (~scanf("%d%d%d", &n, &k, &m) && n && m && k) solve();
    return 0;
}
