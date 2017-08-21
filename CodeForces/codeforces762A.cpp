// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 17 A                        *
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

int64 n, k;
vector<int64> table;

int main()
{
    cin >> n >> k;
    for (int64 i = 1; i * i <= n; i ++)
    {
        if (n % i == 0)
        {
            table.push_back(i);
            if (i * i != n)
            {
                table.push_back(n / i);
            }
        }
    }
    // for (auto i : table) cout << i << " "; cout << endl;
    if (table.size() < k) { puts("-1"); return 0; }
    sort(table.begin(), table.end());
    cout << table[k - 1] << endl;
    return 0;
}