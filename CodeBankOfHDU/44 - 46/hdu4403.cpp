// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4403                                                 *
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

string src;
int64 res;
const string endflag = "END";
vector<int64> vec;

int64 getNumber(int st, int ed) /// [st, ed)
{
    int64 d = src[st] - '0';
    for (int i = st + 1; i < ed; i++)
    {
        d *= 10;
        d += src[i] - '0';
    }
    return d;
}

void gen1(int st, int ed) /// [st, ed)
{
    int k = ed - st - 1;
    int endf = 1 << k;
    for (int state = 0; state < endf; state++)
    {
        int64 ans = 0;
        int st1 = st;
        for (int j = 0; j < k; j++)
        {
            if (state & (1 << j))
            {
                int64 t = getNumber(st1, st + j + 1);
                st1 = st + j + 1;
                ans += t;
            }
            else continue;
        }
        ans += getNumber(st1, ed);
        vec.push_back(ans);
    }
}

void gen2(int st, int ed) /// [st, ed)
{
    int k = ed - st - 1;
    int endf = 1 << k;
    for (int state = 0; state < endf; state++)
    {
        int64 ans = 0;
        int st1 = st;
        for (int j = 0; j < k; j++)
        {
            if (state & (1 << j))
            {
                int64 t = getNumber(st1, st + j + 1);
                st1 = st + j + 1;
                ans += t;
            }
            else continue;
        }
        ans += (st1 >= ed)? 0 : getNumber(st1, ed);
        if (binary_search(vec.begin(), vec.end(), ans))
            res += upper_bound(vec.begin(), vec.end(), ans)
                 - lower_bound(vec.begin(), vec.end(), ans);
        else res += 0;
    }
}

void solve()
{
    int sz = src.size();
    res = 0;
    for (int pos = 0; pos + 1 < sz; pos++)
    {
        vec.clear();
        gen1(0, pos + 1);
        sort(vec.begin(), vec.end());
        gen2(pos + 1, sz);
    }
    cout << res << endl;
}

int main()
{
    while (cin >> src)
    {
        res = 0;
        if (src == endflag) break;
        else solve();
    }
    return 0;
}
