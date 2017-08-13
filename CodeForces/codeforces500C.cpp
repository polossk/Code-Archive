// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 500C                                          *
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

const int MAXN = 505;
const int MAXM = 1005;

void solve()
{
    int n = nextInt();
    int m = nextInt();
    vector<int> w, b;
    for (int i = 0; i < n; i++) w.push_back(nextInt());
    for (int i = 0; i < m; i++) b.push_back(nextInt() - 1);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        // cout << ans << endl;
        vector<bool> used(n, false);
        for (int j = i - 1; j >= 0; j--)
        {
            if (b[i] == b[j]) break;
            // cout << "  i = " << i << ", j = " << j << endl;
            used[b[j]] = true;
        }
        for (int j = 0; j < n; j++) ans += used[j] ? w[j] : 0;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
// g++ G.cpp -o G.exe -std=c++11