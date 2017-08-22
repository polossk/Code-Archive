// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #394 (Div. 2) C                         *
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

const int MAXN = 53;
int n, m;
int dp[MAXN][3];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = 9999;
        string _ = nextStr();
        for (int j = 0; j < m; j++)
        {
            int flag = 0;
            if (isdigit(_[j])) flag = 0;
            else if (isalpha(_[j])) flag = 1;
            else flag = 2;
            dp[i][flag] = min(dp[i][flag], min(j, m - j));
        }
    }
    int ans = 9999;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
    {
        ans = min(ans, dp[i][0] + dp[j][1] + dp[k][2]);
        ans = min(ans, dp[i][1] + dp[j][0] + dp[k][2]);
        ans = min(ans, dp[i][0] + dp[j][2] + dp[k][1]);
        ans = min(ans, dp[i][2] + dp[j][0] + dp[k][1]);
        ans = min(ans, dp[i][2] + dp[j][1] + dp[k][0]);
        ans = min(ans, dp[i][1] + dp[j][2] + dp[k][0]);
    }
    cout << ans << endl;
    return 0;
}