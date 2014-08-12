// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1170                                             *
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

const int   MaxM = 105005;
const int   MOD  = 100000007;
const int64 MaxL = 1e5;
const int64 INF  = 1e10;

int64 m[MaxM], x[MaxM], ctl[MaxM];
int t, tt, cnt, d;
int64 a, b;

inline void ex_gcd(int64 a, int64 b, int64& x, int64& y)
{
    if (b == 0LL) { x = 1LL; y = 0LL; return; }
    ex_gcd(b, a % b, x, y);
    int64 tmp = x; x = y;
    y = tmp - a / b * y;
}

inline int64 inv(int64 a, int64 Mod = MOD)
{
    int64 x = 0LL, y = 0LL;
    ex_gcd(a, Mod, x, y);
    while (x < 0) x += Mod;
    return x;
}

void init()
{
    // m
    for (int64 i = 2; i <= MaxL; i++)
    {
        int64 tmp = i * i;
        while (tmp <= INF) { m[cnt++] = tmp; tmp *= i; }
    }
    sort(m, m + cnt);
    // x
    x[d++] = m[0];
    for (int i = 1; i < cnt; i++)
        if (m[i] != m[i - 1]) x[d++] = m[i];
    // catalan number
    ctl[0] = 0; ctl[1] = 1;
    for (int i = 2; i <= d; i++)
    {
        ctl[i] = ctl[i - 1] * (4 * i - 2) % MOD;
        ctl[i] = ctl[i] * inv(i + 1) % MOD;
    }
}
typedef bool (*judge)(int);
inline bool test1(int y) { return x[y] <  a; }
inline bool test2(int y) { return x[y] <= b; }

int BSearch(int l, int r, bool m)
{
    judge runs = m? test1: test2;
    while (r > l)
    {
        int mid = (r + l) / 2;
        if (runs(mid)) l = mid + 1;
        else r = mid;
    }
    return r;
}

void solve()
{
    a = nextlld(); b = nextlld();
    int indexl = BSearch(0, d, 1);
    int indexr = BSearch(0, d, 0);
    int64 ans = ctl[indexr - indexl];
    printf("Case %d: %lld\n", ++tt, ans);
}

int main()
{
    init();
    t = nextInt(); while (t--) solve();
    return 0;
}
