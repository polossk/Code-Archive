// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 729D                                          *
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

int main()
{
    int n = nextInt();
    int a = nextInt();
    int b = nextInt();
    int k = nextInt();
    string s = nextStr();
    vector<int> pos;
    int padding = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '0') { padding = 0; continue; }
        padding++;
        if (padding == b) { padding -= b; pos.push_back(1 + i); }
    }
    int ans = pos.size() - a + 1;
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
    {
        if (i == 0) { printf("%d", pos[i]); }
        else printf(" %d", pos[i]);
    }
    puts("");
    return 0;
}
// g++ F.cpp -o F.exe -std=c++11