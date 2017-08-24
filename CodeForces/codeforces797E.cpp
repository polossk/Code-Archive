// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 19 E                        *
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
const int MAXD = 333; // SQRT(MAXN)

int dp[MAXN][MAXD];

int main()
{
    int n = nextInt();
    vector<int> a = { 0 };
    for (int i = 0; i < n; i++) a.push_back(nextInt());
    for (int i = 0; i < MAXD; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            int nxt = j + a[j] + i;
            if (nxt > n) dp[j][i] = 1;
            else dp[j][i] = dp[nxt][i] + 1;
        }
    }
    int q = nextInt();
    while (q--)
    {
        int p = nextInt(); int k = nextInt();
        if (k < MAXD) { cout << dp[p][k] << endl; continue; }
        int hoge = 0;
        while (p <= n) { p += a[p] + k; hoge++; }
        cout << hoge << endl;
    }
    return 0;
}