// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
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

const int64 MaxX = 1000000000;
int64 a, b, c;
vector<int64> ans;

inline int64 sum(int64 x)
{
    int64 ans = 0;
    while (x) ans += x % 10, x /= 10;
    return ans;
}

inline int64 powi(int64 x, int64 k)
{
    int64 ans = 1;
    for (int64 i = 0; i < k; i++) ans *= x;
    return ans;
}

void solve()
{
    int64 s = 1; ans.clear();
    for (s = 1; s <= 81; s++)
    {
        int64 x = b * powi(s, a) + c;
        if (x > MaxX) continue;
        if (s == sum(x)) ans.push_back(x);
    }
    if (ans.size())
    {
        int sz = ans.size();
        cout << sz << endl;
        for (int i = 0; i < sz; i++) cout << ans[i] << " ";
        cout << endl;
    }
    else puts("0");
}

int main()
{
    while (cin >> a >> b >> c) solve();
    return 0;
}