// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1276                                             *
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

const int64 INF = 1e12;
vector<int64> num;
int t, tt, endflag;
int64 a, b;

void gen(int digit, int64 cur)
{
    if (cur > INF) return;
    if (cur != 0) num.push_back(cur);
    gen(digit + 1, cur * 10 + 4);
    gen(digit + 1, cur * 10 + 7);
}

void dfs(int64 cur, int index, int endflag)
{
    if (cur != 1 && cur != 0) num.push_back(cur);
    for (int i = index; i < endflag; i++)
        if (num[i] * cur <= INF && num[i] * cur > 0)
            dfs(cur * num[i], i, endflag);
        else break;
}

inline void init()
{
    gen(0, 0);
    sort(num.begin(), num.end());
    endflag = num.size();
    dfs(1, 0, endflag);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    endflag = num.size();
}

typedef bool (*judge)(int64);
inline bool testa(int64 x) { return num[x] <  a; }
inline bool testb(int64 x) { return num[x] <= b; }

int64 Bsearch(int64 l, int64 r, bool isA)
{
    judge runs = isA? testa: testb;
    while (r > l)
    {
        int64 mid = (r + l) / 2;
        if (runs(mid)) l = mid + 1;
        else r = mid;
    }
    return r;
}

void solve()
{
    a = nextlld(); b = nextlld();
    int64 l = Bsearch(0, endflag, 1);
    int64 r = Bsearch(0, endflag, 0);
    printf("Case %d: %d\n", ++tt, r - l);
}

int main()
{
    init();
    t = nextInt(); while (t--) solve();
    return 0;
}
