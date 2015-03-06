// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 712                                                  *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！

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

int n, tt;
string heap, name[8], lst;
bool value[8];

void solve()
{
    fill(value, value + 8, 0);
    printf("S-Tree #%d:\n", ++tt);
    for (int i = 0; i < n; i++)
        cin >> name[i];
    int length = 1 << n;
    cin >> heap;
    int q = nextInt();
    while (q--)
    {
        cin >> lst;
        for (int i = 0; i < n; i++)
            value[i] = lst[name[i][1] - '1'] == '1';
        int pos = 1;
        for (int i = 0; i < n; i++)
            pos = value[i] ? pos * 2 + 1: pos * 2;
        putchar(heap[pos - length]);
    }
    puts("\n");
}

int main()
{
    while (cin >> n && n) solve();
    return 0;
}
