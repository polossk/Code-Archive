// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   UVa 127                                                  *
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

const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";
const bool WIN  = true;
const bool LOSE = false;

struct card { char num, col; };
card pile[52][52];
char temp[2];
int top[52];

inline bool eql(const card& a, const card& b)
{
    return a.num == b.num || a.col == b.col;
}

inline int getCard(int& x, int& y, int pos)
{
    int prev = 1, num = 0;
    x = y = -1;
    for (int i = pos - 1; i >= 0; i--)
    {
        if (top[i] > 0) num++;
        if (num == 1 && prev) { y = i; prev =  0; }
        if (num == 3) { x = i; break; }
    }
    if (x >= 0 || y >= 0) return 1;
    else return 0;
}

inline bool move(int x, int& i)
{
    if (x >= 0 && eql(pile[i][top[i] - 1], pile[x][top[x] - 1]))
    {
        pile[x][top[x]].num = pile[i][top[i] - 1].num;
        pile[x][top[x]].col = pile[i][top[i] - 1].col;
        top[x]++; top[i]--;
        i = x - 1; return 1;
    }
    else return 0;
}

void solve()
{
    memset(top, 0, sizeof(top));
    memset(pile, 0, sizeof(pile));
    pile[0][top[0]].num = temp[0];
    pile[0][top[0]++].col = temp[1];
    for (int i = 1; i < 52; i++)
    {
        scanf("%s", temp);
        pile[i][top[i]].num = temp[0];
        pile[i][top[i]++].col = temp[1];
    }
    for (int i = 1; i < 52; i++)
    {
        int x = -1, y = -1;
        if (top[i] == 0) continue;
        if (!getCard(x, y, i)) continue;
        if (move(x, i)) continue;
        if (move(y, i)) continue;
    }
    int tot = 0;
    for (int i = 0; i < 52; i++)
        tot += (top[i] > 0);
    if (tot == 1) puts("1 pile remaining: 52");
    else
    {
        printf("%d piles remaining:", tot);
        for (int i = 0; i < 52; i++)
            top[i] > 0 ? printf(" %d", top[i]): 1;
        puts("");
    }
}

int main()
{
    while (~scanf("%s", temp) && temp[0] != '#') solve();
    return 0;
}
