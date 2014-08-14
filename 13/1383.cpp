// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1383                                             *
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

struct pnt{ int64 x, y; };
struct itv{ int64 st, ed; itv() { st = 0LL, ed = 0LL; } };

inline bool operator<(const itv& a, const itv& b) { return a.ed < b.ed; }
template<class T> inline T SQR(T a) { return a * a; }

const int64 INF = 1 << 62;
const int MaxN = 10005;
const itv ZERO;
pnt data[MaxN];
itv axis[MaxN];
int64 k, n, s, d;

int t, tt;

bool test(int64 x)
{
    fill(axis, axis + n, ZERO);
    for (int i = 0; i < n; i++)
    {
        if (data[i].y + x > d) return false;
        int64 tmp = (int64)(sqrt(double( SQR(d) - SQR(data[i].y + x) )));
        axis[i].st = data[i].x - tmp;
        axis[i].ed = data[i].x + tmp;
    }
    int64 ans = 0;
    sort(axis, axis + n);
    for (int i = 0; i < n; i++)
    {
        if (++ans > s) return false;
        int tmp = i + 1;
        while (axis[tmp].st <= axis[i].ed)
            if (++tmp >= n) break;
        i = tmp - 1;
    }
    return ans <= s;
}

int64 Bsearch(int64 l, int64 r, bool& flag)
{
    int64 ans = 0; flag = 0;
    while (r >= l)
    {
        int64 mid = (r + l) / 2;
        if (test(mid)) flag = 1, l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return ans;
}

void solve()
{
    k = nextlld(); n = nextlld();
    s = nextlld(); d = nextlld();
    for (int i = 0; i < n; i++)
    {
        data[i].x = nextlld();
        data[i].y = nextlld() - k;
    }
    bool flag = 0;
    int64 ans = Bsearch(0, d, flag);
    if (flag) printf("Case %d: %lld\n", ++tt, ans);
    else printf("Case %d: impossible\n", ++tt);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
