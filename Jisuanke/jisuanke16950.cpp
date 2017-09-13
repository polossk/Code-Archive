#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
// inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MAX_ = 51;

void solve()
{
    int n = nextInt();
    int m = nextInt();
    vector<int> a[MAX_], b[MAX_];
    for (int i = 1; i <= n; i++)
    {
        int _ = nextInt();
        a[nextInt()].push_back(_);
    }
    for (int i = 1; i <= m; i++)
    {
        int _1 = nextInt();
        int _2 = nextInt();
        for (int j = 0, sz = a[_1].size(); j < sz; j++)
        {
            b[a[_1][j]].push_back(_2);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(b[i].begin(), b[i].end());
        for (int j = 0, sz = b[i].size(); j < sz; j++)
        {
            if (j != 0 && b[i][j] == b[i][j-1]) continue;
            printf("%d %d\n", i, b[i][j]);
        }
    }
    puts("");
}

int main()
{
    int _ = nextInt();
    while (_--) solve();
    return 0;
}