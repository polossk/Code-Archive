// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 5037                                                 *
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

int tt, n, m, l;

void solve()
{
    n = nextInt(); m = nextInt(); l = nextInt();
    vector<int> rocks;
    for (int i = 0; i < n; i++) rocks.push_back(nextInt());
    sort(rocks.begin(), rocks.end()); rocks.push_back(m);
    int ans = 0, pos = 0, last = -l;
    for (int i = 0; i <= n; i++)
    {
        // cout << ans << " " << pos << " " << last << endl;
        int dis = rocks[i] - pos;
        ans += dis / (l + 1) * 2;
        last += dis / (l + 1) * (l + 1);
        if (rocks[i] - last > l)
        {
            last = pos + dis / (l + 1) * (l + 1);
            ans++;
        }
        pos = rocks[i];
    }
    printf("Case #%d: %d\n", ++tt, ans);
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
// g++ C.cpp -o C.exe -std=c++11