#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
// inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

int64 r[30] = {
    0, 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449,
    11309768, 65918161, 384199200, 2239277041, 13051463048,
    76069501249, 443365544448, 2584123765441, 15061377048200,
    87784138523761, 511643454094368, 2982076586042449,
    17380816062160328, 101302819786919521
}; // http://oeis.org/A001108

int64 cr[30], k_factor[30][2];

void init()
{
    cr[0] = 0;
    k_factor[1][0] = 1; k_factor[1][1] = 1;
    for (int i = 1; i + 1 < 40; i++)
    {
        int64 k = k_factor[i][0] * k_factor[i][1];
        k_factor[i + 1][0] = k_factor[i][0] + k_factor[i][1];
        k_factor[i + 1][1] = k_factor[i + 1][0] + k_factor[i][0];
        cr[i] = ceil((sqrt(8.0 * k * k + 1) - 1) / 2);
    }
}

int tt;

void solve()
{
    int64 n = nextlld();
    int64 ans = 0;
    for (int i = 0; i < 40; i++)
    {
        cout << n << " <-> " << r[i] << endl;
        if (r[i] < n) continue;
        ans = r[i]; break;
    }
    printf("Case #%d: %lld\n", ++tt, ans);
}

int main()
{
    init();
    int _ = nextInt();
    while (_--) solve();
    return 0;
}