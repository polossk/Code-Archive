// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1107                                             *
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

const char aye[] = "Yes";
const char nay[] = "No";
typedef pair<int, int> pnt;
pnt s1, s2, sq;
int t, tt, q;
bool test;

inline bool query()
{
    sq.first = nextInt(); sq.second = nextInt();
    if (sq.first > s1.first && sq.first < s2.first
    && sq.second > s1.second && sq.second < s2.second)
        return true;
    else return false;
}

void solve()
{
    s1.first = nextInt(); s1.second = nextInt();
    s2.first = nextInt(); s2.second = nextInt();
    q = nextInt();
    printf("Case %d:\n", ++tt);
    for (int i = 0; i < q; i++) printf("%s\n", query()? aye: nay);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
