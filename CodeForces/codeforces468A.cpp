// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #268 Div.2 C                                             *
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

int n;

void solve()
{
    if (n < 4)  puts("NO");
    else
    {
        puts("YES");
        if (n & 1)
        {
            printf("4 * 5 = 20\n");
            printf("20 + 3 = 23\n");
            printf("23 + 2 = 25\n");
            printf("25 - 1 = 24\n");
            for (int i = 6; i <= n; i += 2)
            {
                printf("%d - %d = 1\n",i + 1,i);
                printf("1 * 24 = 24\n");
            }
        }
        else
        {
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
            for (int i = 5; i <= n; i += 2)
            {
                printf("%d - %d = 1\n",i + 1,i);
                printf("1 * 24 = 24\n");
            }
        }
    }
}

int main()
{
    n = nextInt();
    solve();
    return 0;
}