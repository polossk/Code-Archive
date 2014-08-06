// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1305                                             *
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

typedef complex<int> pnt;
typedef complex<int> vct;
#define x real()
#define y imag()
int operator^(const vct& a, const vct& b)
{
    return a.x * b.y - a.y * b.x;
}

int t, tt;

void solve()
{
    pnt p[4];
    for (int i = 0; i < 3; i++)
    {
        p[i].x = nextInt(); p[i].y = nextInt();
    }
    vct v1; v1 = p[1] - p[0];
    vct v2; v2 = p[2] - p[1];
    p[3] = p[0] + p[2] - p[1];
    int s = v1 ^ v2;
    printf("Case %d: %d %d %d\n", ++tt, p[3].x, p[3].y, abs(s));
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
