// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

typedef pair<int, int> pkg;
const int MaxN = 10005;
int t, tt;
int n, m, a[MaxN];

void solve()
{
    n = nextInt(); m = nextInt();
    for (int i = 1; i <= n; i++) a[i] = nextInt();
    sort(a + 1, a + n + 1);
    priority_queue<pkg, vector<pkg>, greater<pkg> > pq;
    pq.push(make_pair(a[1], 1));
    int ans = 0;
    while (m--)
    {
        ans = pq.top().first;
        pkg t = pq.top(); pq.pop();
        if (t.second == n) continue;
        pq.push(make_pair(t.first + a[t.second + 1], t.second + 1));
        pq.push(make_pair(t.first - a[t.second] +  a[t.second + 1], t.second + 1));
    }
    printf("Case #%d: %d\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
