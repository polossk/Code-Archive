// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uvalive 7146                                             *
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

int tt, n, m;


void solve()
{
    n = nextInt(); m = nextInt();
    // (first, second) => (DEF, ATK)
    vector<pair<int, int> > offence, enemy;
    for (int i = 0; i < n; i++)
        offence.push_back(make_pair(nextInt(), nextInt()));
    for (int i = 0; i < m; i++)
        enemy.push_back(make_pair(nextInt(), nextInt()));
    sort(offence.begin(), offence.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) -> bool
        {
            return a.second > b.second;
        });
    sort(enemy.begin(), enemy.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) -> bool
        {
            return a.first > b.first;
        });
    multiset<int> hoge;
    int ans = n;
    for (int i = 0, j = 0; j < m; j++)
    {
        while (i < n && offence[i].second >= enemy[j].first)
            hoge.insert(offence[i++].first);
        if (hoge.empty()) { ans = -1; break; }
        auto it = hoge.upper_bound(enemy[j].second);
        if (it != hoge.end()) hoge.erase(it);
        else { hoge.erase(hoge.begin()); ans--; }
    }
    printf("Case #%d: %d\n", ++tt, ans);
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
// g++ B.cpp -o B.exe -std=c++11