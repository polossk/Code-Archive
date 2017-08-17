// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
*****************************************************************************/

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

const int MaxN = 200005;
int64 b[MaxN];
int64 n, x, y;
int64 nx, ny;

void solve()
{
    x = 0, y = LONG_LONG_MAX;
    nx = ny = 1;
    for (int i = 0; i < n; i++)
    {
        b[i] = nextlld();
        if (b[i] > x) x = b[i], nx = 1LL;
        else if (b[i] == x) nx++;
        if (b[i] < y) y = b[i], ny = 1LL;
        else if (b[i] == y) ny++;
        else continue;
    }
    if (x == y)
        cout << "0 " << n * (n - 1LL) / 2LL << endl;
    else
        cout << x - y << " " << nx * ny << endl;
    //printf("%d %d\n", x - y, nx * ny);
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}