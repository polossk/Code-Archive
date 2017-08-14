// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   bzoj 2565                                                *
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

const int MAXN = 100000 + 10;
char ma[MAXN << 1], s[MAXN];
int p[MAXN << 1], LX[MAXN << 1], RX[MAXN << 1];

void manacher(int len2, int buf_[])
{
    int mx = 0, id = 0, nbuf = 0;
    for (int i = 0; i < len2; i++)
    {
        p[i] = mx > i ? min(p[id * 2 - i], mx - i) : 1;
        while (ma[i + p[i]] == ma[i - p[i]]) p[i]++;
        if (updateMax(mx, i + p[i]))
        {
            id = i;
            while (nbuf < mx)
            {
                buf_[nbuf] = nbuf - i;
                nbuf++;
            }
        }
    }
}

void solve()
{
    int len = strlen(s), len2 = 0;
    ma[len2++] = '$'; ma[len2++] = '#';
    for (int i = 0; i < len; i++)
    {
        ma[len2++] = s[i]; ma[len2++] = '#';
    }
    ma[len2++] = '^'; ma[len2] = 0;
    manacher(len2, LX);
    std::reverse(ma, ma + len2);
    manacher(len2, RX);
    int ans = 0;
    for (int i = 1; i < len2; i++)
    {
        updateMax(ans, LX[i - 1] + RX[len2 - i]);
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%s", s); solve();
    return 0;
}