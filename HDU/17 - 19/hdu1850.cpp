// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 1850                                                 *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

int n;

void solve()
{
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(nextInt());
    int sg_state = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());
    // cout << sg_state <<endl;
    int ret = 0;
    for (auto e : a)
    {
        if (e > (sg_state ^ e)) ret++;
    }
    cout << ret << endl;
}


int main()
{
    while (scanf("%d", &n) && n) solve();
    return 0;
}