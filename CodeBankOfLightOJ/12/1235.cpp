// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1235                                             *
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

const int MaxN = 32;
const char aye[] = "Yes";
const char nay[] = "No";

vector<int> va, vb;
int n, k, a[MaxN];
int t, tt;

void dfs(vector<int>& data, int sum, int cur, int endflag)
{
    if (cur == endflag) { data.push_back(sum); return; }
    else for(int i = 0; i < 3; i++)
        dfs(data, sum + a[cur] * i, cur + 1, endflag);
}

void solve()
{
    va.clear(); vb.clear();
    n = nextInt(); k = nextInt();
    for (int i = 0; i < n; i++) a[i] = nextInt();
    dfs(va, 0, 0, n / 2);
    dfs(vb, 0, n / 2, n);
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    bool flag = 0;
    for (int i = 0, sz = vb.size(); i < sz; i++)
        if (k == vb[i] + *(lower_bound(va.begin(), va.end(), k - vb[i])))
    {
        flag = 1; break;
    }
    printf("Case %d: %s\n", ++tt, flag? aye: nay);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
