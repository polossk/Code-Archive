// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   A                                                        *
*****************************************************************************/

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
bool visit[1000005];
int main()
{
    int t, n, i, a[500], j, tmp;
    t = nextInt();
    while (t--)
    {
        n = nextInt();
        for (i = 0; i < n; i++) a[i] = nextInt();
        memset(visit, 0, sizeof(bool) * n); // 要多少初始多少
        bool ok;
        for (i = n; ; i++) // 从n开始
        {
            ok = 1;
            for (j = 0; j < n; j++)
            {
                tmp = a[j] % i;
                if (visit[tmp] == 0) visit[tmp] = 1;
                else
                {
                    ok = 0;
                    memset(visit, 0, sizeof(bool) * i); // 要多少初始多少
                    break;
                }
            }
            if (ok == 1) { printf("%d\n", i); break; }
        }
    }
    return 0;
}
