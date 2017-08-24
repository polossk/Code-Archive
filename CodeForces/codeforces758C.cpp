// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #392 (Div. 2) C                         *
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

const int MAXN = 102;
const int MAXM = 102;

int64 cnt[MAXN][MAXM];

int main()
{
    int64 n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<pair<int, int> > name_list;
    if (n == 1)
    {
        for (int i = 0; i < m; i++)
            name_list.push_back(make_pair(1, i + 1));
    }
    else
    {
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= m; j++)
                name_list.push_back(make_pair(i, j));
        for (int i = n; i > 1; i--)
            for (int j = 1; j <= m; j++)
                name_list.push_back(make_pair(i, j));
    }
    int64 turn_cap = name_list.size();
    int64 turns = k / turn_cap;
    int64 lasts = k % turn_cap;
    for (auto e : name_list)
        cnt[e.first][e.second] += turns;
    for (auto e : name_list)
    {
        if (lasts == 0) break;
        cnt[e.first][e.second]++;
        lasts--;
    }
    int64 ans1 = 0, ans2 = 1LL << 60, ans3 = cnt[x][y];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        ans1 = max(ans1, cnt[i][j]);
        ans2 = min(ans2, cnt[i][j]);
    }
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}