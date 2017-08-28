// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 523C                                          *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

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

int main()
{
    string s1 = nextStr();
    string s2 = nextStr();
    int l, r, l1 = s1.size(), l2 = s2.size();
    for (int i = 0, p = 0; i < l2 && p < l1; i++)
    {
        if (s1[p] == s2[i]) p++;
        if (p > l1 - 1) l = i;
    }
    for (int i = l2 - 1, p = l1 - 1; i >= 0 && p >= 0; i--)
    {
        if (s1[p] == s2[i]) p--;
        if (p < 0) r = i;
    }
    printf("%d\n", max(r - l, 0));
    return 0;
}
