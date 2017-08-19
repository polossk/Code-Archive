// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #390 Div.2 A                                             *
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
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(nextInt());
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum != 0)
    {
        cout << "YES\n" << 1 << endl << 1 << " " << n << endl;
    }
    else if (0 == accumulate(a.begin(), a.end(), 0, [](int _, int b){ return abs(_) + abs(b); }))
        cout << "NO" << endl;
    else
    {
        for (int i = 0; i < n; i++) if (a[i] != 0)
        {
            cout << "YES\n" << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            break;
        }
    }
    return 0;
}