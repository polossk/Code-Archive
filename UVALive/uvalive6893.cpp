// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uvalive 6893                                             *
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

const int MAXN = 2003;
const unsigned long long HASH1 = 7;
const unsigned long long HASH2 = 11;

int hp, wp, hm, wm;

char sp[MAXN][MAXN], sm[MAXN][MAXN];

unsigned long long a[MAXN][MAXN], b[MAXN][MAXN];

void solve()
{
    for (int i = 0; i < hp; i++) scanf("%s", sp[i]);
    for (int i = 0; i < hm; i++) scanf("%s", sm[i]);
    
    for (int i = 0; i < hp; i++)
        for (int j = 0; j < wp; j++)
            sp[i][j] = sp[i][j] == 'o';
    for (int i = 0; i < hm; i++)
        for (int j = 0; j < wm; j++)
            sm[i][j] = sm[i][j] == 'o';

    unsigned long long target = 0, ans = 0;
    for (int i = 0; i < hp; i++)
    {
        unsigned long long _ = 0ULL;
        for (int j = 0; j < wp; j++)
            _ = _ * HASH1 + sp[i][j];
        target = target * HASH2 + _;
    }

    unsigned long long hoge = 1ULL;
    for (int j = 0; j < wp; j++) hoge *= HASH1;
    for (int i = 0; i < hm; i++)
    {
        unsigned long long _ = 0ULL;
        for (int j = 0; j < wp; j++)
            _ = _ * HASH1 + sm[i][j];
        a[i][wp - 1] = _;
        for (int j = wp; j < wm; j++)
            a[i][j] = a[i][j - 1] * HASH1 - sm[i][j - wp] * hoge + sm[i][j];
    }

    unsigned long long piyo = 1ULL;
    for (int i = 0; i < hp; i++) piyo *= HASH2;
    for (int j = wp - 1; j < wm; j++)
    {
        unsigned long long _ = 0ULL;
        for (int i = 0; i < hp; i++)
            _ = _ * HASH2 + a[i][j];
        b[hp - 1][j] = _;
        ans += _ == target;
        for (int i = hp; i < hm; i++)
        {
            b[i][j] = b[i - 1][j] * HASH2 - a[i - hp][j] * piyo + a[i][j];
            ans += b[i][j] == target;
        }
    }
    cout << ans << endl;
}

int main()
{
    while (~scanf("%d%d%d%d", &hp, &wp, &hm, &wm)) solve();
    return 0;
}