// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1354                                             *
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
int a, b, c, d;

void solve()
{
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    bitset<8> e1(a), e2(b), e3(c), e4(d);
    string str, res;
    cin >> str;
    res =  e1.to_string() + '.';
    res += e2.to_string() + '.';
    res += e3.to_string() + '.';
    res += e4.to_string();
    if (str == res)
        printf("Case %d: %s\n", ++tt, aye);
    else printf("Case %d: %s\n", ++tt, nay);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
