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


void solve()
{
    int n = nextInt();
    int b = nextInt();
    vector<int> vc, vd;
    for (int i = 0; i < n; i++) vc.push_back(nextInt());
    for (int i = 1; i < n; i++) vd.push_back(nextInt());
    bool flag = true;
    int ans = vc.front();
    for (int i = 1; i < n; i++)
    {
        if (ans < vd[i - 1] * b) { flag = false; break; }
        ans -= vd[i - 1] * b;
        ans += vc[i];
    }
    puts(flag ? "Yes" : "No");
}

int main()
{
    int _ = nextInt();
    while (_--) solve();
    return 0;
}