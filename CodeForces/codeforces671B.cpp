// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 671B                                          *
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

const int MAXN = 500000 + 5;

int n, k;
vector<int> c;

void run()
{
    sort(c.begin(), c.end());
    int prev = c[0], kache = k;
    for (int i = 1; i < n; i++)
    {
        int64 hoge = (c[i] - prev) * int64(i);
        if (hoge <= kache) { kache -= hoge; prev = c[i]; }
    }
    // num of increased: j
    int j = -1; while (j + 1 < n && c[j + 1] <= prev) j++;
    int a = kache / (j + 1), b = kache % (j + 1);
    for (int i = 0; i <= j; i++) c[i] = prev + a + (i < b);
}

int main()
{
    n = nextInt(); k = nextInt();
    for (int i = 0; i < n; i++) c.push_back(nextInt());
    run(); std::transform(c.begin(), c.end(), c.begin(),
        [](int _) -> int { return -_; });
    run(); std::transform(c.begin(), c.end(), c.begin(),
        [](int _) -> int { return -_; });
    sort(c.begin(), c.end());
    printf("%d\n", c.back() - c.front());
    return 0;
}
// g++ G.cpp -o G.exe -std=c++11
