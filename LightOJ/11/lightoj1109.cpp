// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1109                                             *
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

const int MaxN = 1005;
typedef pair<int, int> pnt;
pnt s[MaxN];
int t, tt, q;

bool cmp(const pnt& a, const pnt& b)
{
    return (a.second < b.second)
    || ((a.second == b.second) && (a.first > b.first));
}

void init()
{
    for (int i = 0; i < MaxN; i++)
        s[i].first = i, s[i].second = 0;
    for (int i = 1; i < MaxN; i++)
        for (int j = i; j < MaxN; j += i)
            s[j].second++;
    sort(s + 0, s + 1001, cmp);
}

void solve()
{
    q = nextInt();
    printf("Case %d: %d\n", ++tt, s[q].first);
}

int main()
{
    init();
    t = nextInt(); while (t--) solve();
    return 0;
}
