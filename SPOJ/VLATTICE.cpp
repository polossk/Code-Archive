// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   spoj VLATTICE                                            *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MAXN = 1000000 + 5;
int mu[MAXN], sumu[MAXN];

void getMu()
{
    for (int i = 1; i < MAXN; i++)
    {
        int target = (i == 1) ? 1 : 0;
        int delta = target - mu[i];
        mu[i] = delta;
        for (int j = i << 1; j < MAXN; j += i)
            mu[j] += delta;
    }
    std::partial_sum(mu, mu + MAXN, sumu);
//     for (int i = 1; i < MAXN; i++)
//         sumu[i] = mu[i] + sumu[i - 1];
}

// calculate the pairs of (i, j) when gcd(i, j) = 1
// which (i, j) is in grid [1..a][1..b]
int64 calc(int a, int b)
{
    int n = min(a, b), d1, d2, n1, n2, nn;
    int64 ans = 0;
    for (int i = 1; i <= n; i = nn + 1)
    {
        d1 = a / i; d2 = b / i;
        n1 = a / d1; n2 = b / d2;
        nn = min(n1, n2);
        ans += (int64) d1 * d2 * (sumu[nn] - sumu[i - 1]);
    }
    return ans;
}

// calculate the pairs of (i, j, k) when gcd(i, j, k) = 1
// which (i, j, k) is in cube [1..a][1..b][1..c]
int64 calc(int a, int b, int c)
{
    int n = min(a, min(b, c));
    int d1, d2, d3, n1, n2, n3, nn;
    int64 ans = 0;
    for (int i = 1; i <= n; i = nn + 1)
    {
        d1 = a / i; d2 = b / i; d3 = c / i;
        n1 = a / d1; n2 = b / d2; n3 = c / d3;
        nn = min(n1, min(n2, n3));
        ans += (int64) d1 * d2 * d3 * (sumu[nn] - sumu[i - 1]);
    }
    return ans;
}

int64 looking(int a, int b, int c)
{
    return 3 + calc(a, b, c) + calc(a, b) + calc(b, c) + calc(c, a);
}

void solve()
{
    int n = nextInt();
    printf("%lld\n", looking(n, n, n));
}

int main()
{
    getMu();
    int t = nextInt();
    while (t--) solve();
    return 0;
}
