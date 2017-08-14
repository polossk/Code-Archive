// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 3818                                                 *
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

const char aye[] = "Yes";
const char nay[] = "No";
string str;
int t;

inline string modify(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i])) res += s[i];
    return res;
}

inline bool testSize1(int sz, int i, int j) { return i * 3 + j * 2 == sz; }

inline bool testSize2(int sz, int i, int j) { return sz <= (i + j) * 3; }

inline bool judge1(string& s, int i)
{
    for (int j = 0; j < i; j++) if (s[j] != s[j + 1])
        return false;
    return true;
}

inline bool judge2(string& s, int i, int j, int c)
{
    bool flag = true;
    if (i == j)
    {
        for (int k = 0; k < i; k++)
            if (s[k] != s[k + i]) { flag = false; break; }
        if (flag) return true;
    }
    if (i == c)
    {
        flag = true;
        for (int k = 0; k < i; k++)
            if (s[k] != s[k + (i + j) * 2]) { flag = false; break; }
        if (flag) return true;
    }
    if (j == c)
    {
        flag = true;
        for (int k = 0; k < j; k++)
            if (s[k + i] != s[k + (i + j) * 2]) { flag = false; break; }
        if (flag) return true;
    }
    return false;
}

bool isABABA(string s)
{
    int sz = s.size();
    if (sz < 5) return false;
    for (int i = 1; i < sz; i++)
        for (int j = 1; j < sz; j++)
    {
        if (!testSize1(sz, i, j) || (i == j && judge1(s, i))) continue;
        bool flag = true;
        for (int k = 0; k < i; k++)
        {
            if (s[k] == s[k + i + j] && s[k] == s[k + i * 2 + j * 2]) continue;
            else { flag = false; break; }
        }
        if (flag)
        {
            for (int k = 0; k < j; k++)
            {
                if (s[k + i] == s[k + i * 2 + j]) continue;
                else { flag = false; break; }
            }
        }
        if (flag) return flag;
    }
    return false;
}

bool isABABCAB(string s)
{
    int sz = s.size();
    if (sz < 7) return false;
    for (int i = 1; i < sz; i++)
        for (int j = 1; j < sz; j++)
    {
        if (!testSize2(sz, i, j) && judge2(s, i, j, sz - (i + j) * 3)) continue;
        if ((i + j) * 3 < sz)
        {
            int c = sz - (i + j) * 3;
            bool flag = true;
            for (int k = 0; k < i; k++)
            {
                if (s[k] == s[k + i + j] &&s[k] == s[k + i * 2 + j * 2 + c]) continue;
                else { flag = false; break; }
            }
            if (flag)
            {
                for (int k = 0; k < j; k++)
                {
                    if (s[k + i] == s[k + i * 2 + j] && s[k + i] == s[k + i * 3 + j * 2 + c]) continue;
                    else { flag = false; break; }
                }
            }
            if (flag) return flag;
        }
    }
    return false;
}

void solve()
{
    str = nextStr(); str = modify(str);
    if (isABABA(str) || isABABCAB(str)) puts(aye);
    else puts(nay);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}