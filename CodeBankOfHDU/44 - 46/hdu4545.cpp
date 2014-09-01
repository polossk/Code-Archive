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

const int MaxN = 1005;
const int MaxL = 30;
bool a[MaxL][MaxL];
char s1[MaxN], s2[MaxN];
int n, t, tt;

void solve()
{
    scanf(" "); gets(s1); gets(s2);
    n = nextInt();
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        char x = nextChr();
        char y = nextChr();
        a[x - 'a'][y - 'a'] = true;
    }
    int j = 0, sz1 = strlen(s1), sz2 = strlen(s2);
    bool flag = 1;
    for (int i = 0; i < sz1; i++)
    {
        if (j == sz2) break;
        if (s1[i] == s2[j]) j++;
        else
        {
            while (s2[j] != s1[i])
            {
                if (j++ == sz2) { flag = 0; break; }
                if (a[s2[j - 1] - 'a'][s1[i] - 'a'] == 1) break;
            }
        }
    }
    printf("Case #%d: ", ++tt);
    if (flag) printf("happy\n");
    else printf("unhappy\n") ;
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
