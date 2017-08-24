// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 19 A                        *
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

vector<int> factor(int n, int k)
{
    vector<int> ans;
    int now = n;
    for (int i = 2; i <= n / i; i++)
    {
        if (now % i == 0)
        {
            if (k == 1) break;
            while (now % i == 0)
            {
                if (k == 1) break;
                ans.push_back(i); k--; now /= i;
            }
        }
    }
    if (k == 1 && now != 1) { ans.push_back(now); k--; }
    return ans;
}

int main()
{
    int n = nextInt();
    int k = nextInt();
    vector<int> ans = factor(n, k);
    if (k == ans.size())
    {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << " " << ans[i];
        cout << endl;
    }
    else cout << "-1" << endl;
    return 0;
}