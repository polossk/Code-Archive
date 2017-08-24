// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Codeforces Round #402 (Div. 2) C                         *
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

struct Chuco
{
    int64 a, b, d;
    Chuco(int _1, int _2): a(_1), b(_2), d(_1 - _2) {}
    bool operator<(const Chuco& c) const
    {
        return d < c.d;
    }
};

const int MAXN = 200005;
vector<Chuco> blk;
vector<int64> a, b;
int n, k;

int64 eatChuco(int flag, int64 base)
{
    for (int i = 0; i < flag; i++)
        base += blk[i].d;
    return base;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) a.push_back(nextI64());
    for (int i = 0; i < n; i++) b.push_back(nextI64());
    int64 base = std::accumulate(b.begin(), b.end(), 0LL);
    for (int i = 0; i < n; i++) a[i] -= b[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < k || a[i] < 0; i++) base += a[i];
    cout << base << endl;
    return 0;
}