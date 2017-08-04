// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 11111                                                *
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

const int MaxN = 1000010;
const char aye[] = ":-) Matrioshka!";
const char nay[] = ":-( Try again.";

int tmp, cnt, k[MaxN]; char c;
struct Toy
{
    int val, rest;
    Toy(int _ = 0, int __ = 0){ val = _; rest = __; }
};

bool judge()
{
    Toy t(k[0], abs(k[0]));
    stack<Toy> s; s.push(t);
    for (int i = 1; i < cnt; i++)
    {
        if (s.empty()) return false;
        if (k[i] < 0)
        {
            if (abs(k[i]) <s.top().rest)
            {
                Toy p(k[i], abs(k[i]));
                s.push(p);
            }
            else return false;
        }
        if (k[i] > 0)
        {
            if (k[i] + s.top().val == 0)
            {
                if (i + 1 != cnt){ s.pop(); s.top().rest -= k[i]; }
                else s.pop();
            }
            else return false;
        }
    }
    return s.empty();
}

void solve()
{
    k[0] = tmp;
    cnt = 1;
    while (c != '\n') scanf("%d%c", &k[cnt++], &c);
    if (judge()) puts(aye);
    else puts(nay);
}

int main()
{
    while (~scanf("%d%c", &tmp, &c)) solve();
    return 0;
}
