// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   fzu 1759                                                 *
*****************************************************************************/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int64 MAXL = 1000000 + 5;
const int64 MOD = 1e9 + 7;
char s[MAXL];

int64 Phi(int64 n)
{
    int64 ans = n;
    for (int64 i = 2; i * i <= n; i++) if (n % i == 0)
    {
        ans -= ans / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int64 pow_mod(int64 a, int64 b, int64 m = MOD)
{
    int64 ans = 1; a %= m;
    while (b)
    {
        if (b & 1) { ans = (ans * a) % m; b--; }
        b >>= 1; a = (a * a) % m;
    }
    return ans;
}

int64 a, c;

void solve()
{
    int64 p = Phi(c), b = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        b = (b * 10 + s[i] - '0') % p;
    }
    printf("%I64d\n", pow_mod(a, b + p, c));
    return;
}

int main()
{
    while (~scanf("%I64d%s%I64d", &a, s, &c)) solve();
    return 0;
}