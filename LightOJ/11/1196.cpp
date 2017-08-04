// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1196                                             *
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

typedef struct{ int64 x, y; } pnt;
const int MaxN = 100005;
int t, tt, n, q;
pnt poly[MaxN], ps;

inline int64 Xmul(const pnt& O, const pnt& A, const pnt& B)
{
    return O.x * (A.y - B.y) + A.x * (B.y - O.y) + B.x * (O.y - A.y);
}

inline bool isInPoly(const pnt& p)
{
    int l = 1, r = n - 1, mid = 0;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (Xmul(poly[0], poly[mid], p) < 0) r = mid;
        else l = mid;
    }
    if (Xmul(poly[0], poly[l], p) < 0) return false;
    else if (Xmul(poly[l], poly[r], p) < 0) return false;
    else if (Xmul(poly[r], poly[0], p) < 0) return false;
    else return true;
}

void solve()
{
    n = nextInt();
    for (int i = 0; i < n; i++)
    {
        poly[i].x = nextlld();
        poly[i].y = nextlld();
    }
    printf("Case %d:\n", ++tt);
    q = nextInt();
    while (q--)
    {
        ps.x = nextlld(); ps.y = nextlld();
        if (isInPoly(ps)) puts("y");
        else puts("n");
    }
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
