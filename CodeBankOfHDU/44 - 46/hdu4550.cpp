// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   E                                                        *
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

const int MaxL = 105;
int t;
char s[MaxL];

void solve()
{
    scanf(" %s", s);
    int sz = strlen(s), pos = 0, minc = 0xff;
    for (int i = sz - 1; i >= 0; i--)
        if (s[i] != '0' && minc > s[i] - '0')
    {
        minc = s[i] - '0'; pos = i;
    }
    deque<char> ans; ans.push_back(s[0]);
    for (int i = 1; i < sz; i++)
    {
        if (i == pos) ans.push_front(s[i]);
        else if (i > pos) ans.push_back(s[i]);
        else if (s[i] > ans[0]) ans.push_back(s[i]);
        else ans.push_front(s[i]);
    }
    for (int i = 0; i < sz; i++)
    {
        printf("%c", ans.front());
        ans.pop_front();
    }
    puts("");
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
