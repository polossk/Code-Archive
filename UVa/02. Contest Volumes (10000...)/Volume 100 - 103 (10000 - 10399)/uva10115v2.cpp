// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 10115                                                *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
// #pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
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

string s, s1[20], s2[20];
int n;

void solve()
{
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s1[i]);
        getline(cin, s2[i]);
    }
    getline(cin, s);
    for (int i = 0; i < n; i++) while (1)
    {
        string::size_type pos = s.find(s1[i]);
        if (pos == string::npos) break;
        else
            s.replace(pos, s1[i].size(), s2[i]);
    }
    puts(s.c_str());
}

int main()
{
    while (scanf("%d", &n) && n) solve();
    return 0;
}
