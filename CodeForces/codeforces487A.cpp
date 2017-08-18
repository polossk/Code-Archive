// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #278 Div.1 A                                             *
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

int yhp, yat, yde;
int mhp, mat, mde;
int php, pat, pde;

inline int calcBitcoins(int hp, int atk, int def)
{
    return php * hp + pat * atk + pde * def;
}

int calcHP(int dat, int dde)
{
    int nat = yat + dat;
    int nde = yde + dde;
    int mlose = nat - mde; if (mlose < 0) mlose = 0;
    int ylose = mat - nde; if (ylose < 0) ylose = 0;
    if (mlose == 0) return 0x3f3f;
    if (ylose == 0) return 0;
    else
    {
        int t = mhp / mlose + bool(mhp % mlose);
        int hplose = t * ylose + 1;
        int dhp = max(hplose, yhp) - yhp;
        return dhp;
    }
}

void solve()
{
    int res = 0x3f3f3f3f;
    for (int atk = max(yat, mde); atk <= 200; atk++)
        for (int def = yde; def <= 200; def++)
    {
        int dat = atk - yat;
        int dde = def - yde;
        int dhp = calcHP(dat, dde);
        updateMin(res, calcBitcoins(dhp, dat, dde));
    }
    cout << res << endl;
}

int main()
{
    cin >> yhp >> yat >> yde;
    cin >> mhp >> mat >> mde;
    cin >> php >> pat >> pde;
    solve();
    return 0;
}