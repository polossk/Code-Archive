// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   F                                                        *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
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

int gcd(int a, int b)
{
    return (b == 0)? a: gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int t, tt, cnt;
int g, l, yyyy, mm, dd;
bool flag = 0;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool inbound(int l, int r, int v)
{
    return l <= v && v <= r;
}

bool judge(int y, int m, int d)
{
    if (!inbound(1, 12, m)) return false;
    int leap = (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
    if (m == 2) return inbound(1, days[m] + leap, d);
    else return inbound(1, days[m], d);
}

void solve()
{
    g = nextInt(); l = nextInt(); yyyy = nextInt();
    int n = g * l;
    if (l % g != 0) { printf("Case #%d: -1\n", ++tt); return ; }
    cnt = 0; flag = 0;
    for (int i = 1; i <= 12; i++)
    {
        if (n % i != 0) continue;
        int j = n / i;
        if (gcd(i, j) == g && lcm(i, j) == l)
        {
            mm = i; dd = j;
            flag = judge(yyyy, mm, dd);
            cnt += flag;
        }
    }
    if (cnt > 1) printf("Case #%d: 1\n", ++tt);
    else if (cnt == 1) printf("Case #%d: %4d/%02d/%02d\n", ++tt, yyyy, mm, dd);
    else printf("Case #%d: -1\n", ++tt);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
