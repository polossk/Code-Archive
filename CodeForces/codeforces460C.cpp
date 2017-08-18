// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   C                                                        *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
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

typedef pair<int, int> pnt;
const int MaxN = 100005;
int a[MaxN];
pnt p[MaxN];
int n, m, w;

bool test(int x)
{
    int cnt = 0, cur = 0;
    int num = 0, head = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] + cur < x)
        {
            int tmp = x - a[i] - cur;
            p[++num] = make_pair(i + w - 1, tmp);
            cur += tmp; cnt += tmp;
        }
        while (head <= num && p[head].first == i)
        {
            cur -= p[head].second;
            head++;
        }
        if (cnt > m) return false;
    }
    return cnt <= m;
}

int Bsearch(int l, int r)
{
    int res = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (test(mid)) { l = mid + 1; res = mid; }
        else r = mid - 1;
    }
    return res;
}

void solve()
{
    int l = INT_MAX, r = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = nextInt();
        updateMin(l, a[i]);
    }
    r = l + m;
    int ans = Bsearch(l, r);
    cout << ans << endl;
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &w)) solve();
    return 0;
}