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
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MaxN = 1000005;
int n, cnt[MaxN];
int64 f[MaxN];

int main()
{
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        int foo;
        scanf("%d", &foo);
        cnt[foo]++;
    }
    f[0] = 0;
    for (int i = 1; i < MaxN; i++)
    {
        f[i] = (long long)i * cnt[i];
        if (i - 2 >= 0)      f[i] += f[i - 2];
        if (f[i - 1] > f[i]) f[i] = f[i - 1];
    }
    cout << f[MaxN - 1] << endl;
    return 0;
}