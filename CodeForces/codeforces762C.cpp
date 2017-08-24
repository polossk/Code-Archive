// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 17 C                        *
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

string a, b;

int main()
{
    cin >> a >> b;
    int len_a = a.size(), len_b = b.size();
    vector<int> pref(len_b + 1, -1), suff(len_b + 1, -1);
    pref[0] = -1; suff[len_b] = len_a;

    for (int i = 0, idx = 0; i < len_b; i++ )
    {
        idx = pref[i] + 1;
        while (idx < len_a && b[i] != a[idx]) idx++;
        pref[i + 1] = idx;
    }

    for (int i = len_b - 1, idx = 0; i >= 0; i-- )
    {
        idx = suff[i + 1] - 1;
        while (idx >= 0 && b[i] != a[idx]) idx--;
        suff[i] = idx;
    }

    vector<int> res(len_b + 1);
    for (int i = 0; i <= len_b; i++)
    {
        res[i] = upper_bound(suff.begin() + i, suff.end(), pref[i]) - suff.begin();
    }

    int cut_l = 0;
    for (int i = 0; i <= len_b; i++)
    {
        if (pref[i] < len_a && i - res[i] > cut_l - res[cut_l])
            cut_l = i;
    }
    int cut_r = res[cut_l];
    int ret = len_b - cut_r + cut_l;
    string ans = ret == 0 ? "-" : b.substr(0, cut_l) + b.substr(cut_r);
    cout << ans << endl;
    return 0;
}