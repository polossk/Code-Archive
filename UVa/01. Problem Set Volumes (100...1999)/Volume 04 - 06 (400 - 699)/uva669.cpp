// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 669                                                  *
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

const int inf = 0x3f3f3f3f;
const int MAXN = 2048;

int data[MAXN * 2], result[MAXN], tt;

void _build(int& pos, int index, const int& sz)
{
    if (pos >= sz) return;
    if (data[pos] == -1) return;
    result[index] += data[pos++];
    _build(pos, index - 1, sz);
    pos++;
    _build(pos, index + 1, sz);
}

void build(int sz)
{
    int pos = 0;
    _build(pos, 1024, sz);
    int i = 0;
    while (result[i] == 0) i++;
    printf("%d", result[i++]);
    for ( ; result[i] != 0; i++)
        printf(" %d", result[i]);
    puts("\n");
}

void solve()
{
    printf("Case %d:\n", ++tt);
    fill(result, result + MAXN, 0);
    int cnt1 = 1, cnt2 = 0, n = 0;
    while (data[++n] = nextInt())
    {
        if (data[n] == -1) cnt2++;
        else cnt1++;
        if (cnt1 + 1 == cnt2) break;
    }
    build(n);
}

int main()
{
    while (cin >> data[0] && data[0] != -1) solve();
    return 0;
}
