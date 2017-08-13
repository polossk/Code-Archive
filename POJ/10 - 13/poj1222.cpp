// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 1222                                                 *
*****************************************************************************/

#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
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

const int MAXN = 40;

inline int xorsolve(int a[][MAXN], int ans[], int n_equ, int n_var)
{
    // old format: A[][] * x[] = B[]
    // new format: A[][0 .. n - 1] * x[] = A[][n]
    // the last row is B[] so called
    int res = 0, r = 0;
    for (int i = 0, col = 0; i < n_equ && col < n_var; i++, col++)
    {
        int m_row = i;
        for (int j = i + 1; j < n_equ; j++)
            m_row = abs(a[j][col]) > abs(a[m_row][col]) ? j : m_row;
        if (m_row != i) for (int j = i; j < n_var + 1; j++)
            swap(a[i][j], a[m_row][j]);
        if (a[i][col] == 0) { i--; continue; }
        for (int j = i + 1; j < n_equ; j++) if (a[j][col] != 0)
        {
            for (int k = col; k < n_var + 1; k++)
                a[j][k] ^= a[i][k];
        }
    }
    for (int i = n_var - 1; i >= 0; i--)
    {
        ans[i] = a[i][n_var];
        for (int j = i + 1; j < n_var; j++)
            ans[i] ^= (a[i][j] && ans[j]);
    }
    return 0;
}

const int n_equ = 30;
const int n_var = 30;
const int n_row = 5;
const int n_col = 6;
int tt, a[MAXN][MAXN], x[MAXN];

void init()
{
    memset(a, 0, sizeof a);
    for (int i = 0; i < n_row; i++)
        for (int j = 0; j < n_col; j++)
    {
        int _ = i * n_col + j;
        a[_][_] = 1;
        if (i > 0) a[_ - 6][_] = 1;
        if (i < 4) a[_ + 6][_] = 1;
        if (j > 0) a[_ - 1][_] = 1;
        if (j < 5) a[_ + 1][_] = 1;
    }
    for (int i = 0, _ = n_col * n_row; i < _; i++)
        a[i][_] = nextInt();
}

void solve()
{
    init();
    int ret = xorsolve(a, x, n_equ, n_var);
    printf("PUZZLE #%d\n", ++tt);
    for (int i = 0; i < 30; i++)
        printf("%d%c", x[i], i % 6 == 5 ? '\n' : ' ');
    return;
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
