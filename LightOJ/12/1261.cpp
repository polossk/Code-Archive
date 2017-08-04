// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1261                                             *
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

typedef vector<int> vi;
typedef vector<vi> vii;

const char aye[] = "Yes";
const char nay[] = "No";
const int  MaxM  = 35;
const int  MaxN  = 35;
int t, tt, n, m, k, p, tmp;

void solve()
{
    n = nextInt(); m = nextInt(); k = nextInt();
    vii  v2(MaxN); vi   v1(MaxM);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
    {
        tmp = nextInt();
        v2[i].push_back(tmp);
    }
    p = nextInt();
    for (int i = 0; i < p; i++)
    {
        tmp = nextInt();
        v1[tmp] = 1;
    }
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < k; j++)
        {
            if (v2[i][j] < 0 && !v1[-v2[i][j]]) cnt++;
            if (v2[i][j] > 0 &&  v1[ v2[i][j]]) cnt++;
        }
        if (cnt == 0) flag = 1;
    }
    if (flag) printf("Case %d: %s\n", ++tt, nay);
    else      printf("Case %d: %s\n", ++tt, aye);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
