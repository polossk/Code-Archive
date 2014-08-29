// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1414                                             *
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

map<string, int> mm;

void init()
{
    mm["January"] =  1; mm["February"] =  2; mm["March"]     =  3;
    mm["April"]   =  4; mm[ "May"]     =  5; mm["June"]      =  6;
    mm["July"]    =  7; mm["August"]   =  8; mm["September"] =  9;
    mm["October"] = 10; mm["November"] = 11; mm["December"]  = 12;
}

bool isLeap(int yyyy)
{
    if (yyyy % 4 == 0 && yyyy % 100 != 0 || yyyy % 400 == 0)
        return true;
    else return false;
}

int t, tt;
int yy1, yy2, d1, d2, ans, yy;
string m1, m2;
char ch;

void solve()
{
    cin >> m1 >> d1 >> ch >> yy1;
    cin >> m2 >> d2 >> ch >> yy2;
    ans = 0;
    yy = yy1;
    while (yy1 % 4 != 0) yy1++; yy2--;
    if (yy2 >= yy1)
    {
        ans += (yy2 - yy1) / 4 + 1;
        while (yy1 % 100 != 0) yy1++;
        if (yy2 >= yy1)
        {
            ans -= (yy2 - yy1) / 100 + 1;
            while (yy1 % 400 != 0) yy1++;
            if (yy2 >= yy1) ans += (yy2 - yy1) / 400 + 1;
        }
    }
    if (isLeap(yy) && mm[m1] >= 3) ans--;
    if (isLeap(yy2 + 1) && (mm[m2] == 2 && d2 == 29 || mm[m2] > 2)) ans++;
    printf("Case %d: %d\n", ++tt, ans);
}

int main()
{
    init();
    t = nextInt(); while (t--) solve();
    return 0;
}
