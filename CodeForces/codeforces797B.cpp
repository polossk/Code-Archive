// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 19 B                        *
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

const int MAXN = 100000 + 5;

int a[MAXN], dp[MAXN][2];


int main()
{
    int n = nextInt();
    for (int i = 0; i < n; i++) a[i] = nextInt();
    dp[0][abs(a[0]) % 2] = a[0];
    dp[0][1 - abs(a[0]) % 2] = 0x80808080;
    // cout << 0 << ": " << dp[0][0] << " " << dp[0][1] << endl;
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) % 2 == 1)
        {
            // odd
            // cout << dp[i - 1][1] << " " << dp[i - 1][0] + a[i] << " " << a[i] << endl;
            dp[i][1] = max(dp[i - 1][1], max(dp[i - 1][0] + a[i], a[i]) );
            // cout << dp[i][1] << endl;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i] );
        }
        else
        {
            // even
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + a[i] );
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][0] + a[i], a[i]) );
        }
        // cout << i << ": " << dp[i][0] << " " << dp[i][1] << endl;
    }
    int ans = dp[0][1];
    for (int i = 1; i < n; i++) updateMax(ans, dp[i][1]);
    cout << ans << endl;
    return 0;
}