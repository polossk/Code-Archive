// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1133                                             *
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

const int MaxN = 105;
int t, tt, n, m, d, k;
char ch;
int a[MaxN];

void solve()
{
    n = nextInt(); m = nextInt();
    for (int i = 0; i < n; i++) a[i] = nextInt();
    while (m--)
    {
        ch = nextChr();
        if (ch == 'S')
        {
            d = nextInt();
            for (int i = 0; i < n; i++) a[i] += d;
        }
        else if (ch == 'M')
        {
            d = nextInt();
            for (int i = 0; i < n; i++) a[i] *= d;
        }
        else if (ch == 'D')
        {
            d = nextInt();
            for (int i = 0; i < n; i++) a[i] /= d;
        }
        else if (ch == 'P')
        {
            d = nextInt(); k = nextInt();
            swap(a[d], a[k]);
        }
        else reverse(a, a + n);
    }
    printf("Case %d:\n", ++tt);
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
