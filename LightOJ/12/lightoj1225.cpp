// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1225                                             *
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

const char aye[] = "Yes";
const char nay[] = "No";
int t, tt;
char s[15];

void solve()
{
    int sz = 0;
    while (1)
    {
        char ch = getchar();
        if (ch == ' ' || (ch == '0' && sz == 0)) continue;
        else if (ch == '\n') break;
        else s[sz++] = ch;
    }
    bool flag = 1;
    for (int i = 0, j = sz - 1; i <= j; i++, j--)
        if (s[i] == s[j]) continue;
        else { flag = 0; break; }
    if (flag) printf("Case %d: %s\n", ++tt, aye);
    else printf("Case %d: %s\n", ++tt, nay);
}


int main()
{
    t = nextInt(); getchar(); while (t--) solve();
    return 0;
}
