// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   A                                                        *
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

const int MaxN = 300005;
int n, a[MaxN];

void solve()
{
    for (int i = 0; i < n; i++) a[i] = nextInt();
    sort(a, a + n);
    int64 sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += int64(i + 2) * int64(a[i]);
    sum += int64(n) * int64(a[n - 1]);
    cout << sum << endl;
}

int main()
{
    n = nextInt();
    solve();
    return 0;
}