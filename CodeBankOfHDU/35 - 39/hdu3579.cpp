// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   D                                                        *
*****************************************************************************/

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

int64 gcd_ex(int64 a, int64 b, int64& x, int64& y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    int64 d = gcd_ex(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

inline int64 mod(int64 a, int64 m) { return a % m + (a % m > 0? 0: m); }

/// x = ai (mod mi), for i := [0, n)
/// @return legal Equalion? result: -1;
int64 CRT_ex(int n, int a[], int m[])
{
    if (n == 1 && a[0] == 0) return m[0];
    int64 ans = a[0], lcm = m[0];
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        int64 x, y, gcd;
        gcd = gcd_ex(lcm, m[i], x, y);
        if ((a[i] - ans) % gcd) { flag = false; break; }
        int64 tmp = lcm * mod((a[i] - ans) / gcd * x, m[i] / gcd);
        lcm = lcm / gcd * m[i];
        ans = mod(ans + tmp, lcm);
    }
    return flag? ans: -1;
}

const int MaxN = 203;
int t, tt;
int n, a[MaxN], m[MaxN];

void solve()
{
    n = nextInt();
    for (int i = 0; i < n; i++) m[i] = next64d();
    for (int i = 0; i < n; i++) a[i] = next64d();
    printf("Case %d: %I64d\n", ++tt, CRT_ex(n, a, m));
}


int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
