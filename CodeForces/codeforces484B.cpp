// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 484                                          *
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

const int MAXN = 1000010;
int L[MAXN]; bool f[MAXN];

int main()
{
    int n = nextInt();
    vector<int> a;
    for (int i = 0; i < n; ++i) a.push_back(nextInt());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    memset(f, 0, sizeof f); n = a.size();
    for (int i = 0; i < n; i++) f[a[i]] = true;
    L[0] = 0;
    for (int i = 1; i < MAXN; i++) L[i] = f[i] ? i : L[i - 1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = i;
        updateMax(ans, a[n - 1] % a[i]);
        for (int j = 2 * a[i]; j <= a[n - 1]; j += a[i])
            updateMax(ans, L[j - 1]% a[i]);
    }
    printf("%d\n", ans);
    return 0;
}
// g++ F.cpp -o F.exe -std=c++11