// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 2110                                                 *
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

const int MAXN = 100 + 5;
const int MAXL = 10000 + 10;
const int MOD = 10000;

int n, sum, dp[MAXL], fp[MAXL];
vector<int> p, m;

int run()
{
    if (sum % 3 != 0) return -1;
    memset(dp, 0, sizeof dp);
    memset(fp, 0, sizeof fp);
    dp[0] = fp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = sum / 3; j >= 0; j--)
            for (int k = 1; k <= m[i] && j >= k * p[i]; k++)
    {
        dp[j] = (dp[j] + dp[j - k * p[i]]) % MOD;
        fp[j] = (fp[j] | fp[j - k * p[i]]);
    }
    if (!fp[sum / 3]) return -1;
    return dp[sum / 3];
}

void solve()
{
    sum = 0; p.clear(); m.clear();
    for (int i = 0; i < n; i++)
    {
        p.push_back(nextInt());
        m.push_back(nextInt());
        sum += p.back() * m.back();
    }
    int ans = run();
    ans < 0 ? puts("sorry") : printf("%d\n", ans);
}


int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}