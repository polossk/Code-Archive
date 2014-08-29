// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :                                                            *
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

//Computational Geometry
#include <complex>
#define x first
#define y second
typedef pair<double, double> pnt;

const double PI = acos(-1.0);
pnt a, b, c;

inline double dis(const pnt& a, const pnt& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double ds = dx * dx + dy * dy;
    return sqrt(ds);
}

void solve()
{
    b.x = nextDbf(); b.y = nextDbf();
    c.x = nextDbf(); c.y = nextDbf();
    double A = dis(a, b);
    double B = dis(b, c);
    double C = dis(c, a);
    double p = 0.5 * (A + B + C);
    double S = sqrt(p * (p - A) * (p - B) * (p - C));
    double R = (A * B * C) * 0.25 / S;
    double ans = 2 * PI * R;
    // C++
        printf("%0.2lf\n", ans);
    // g++
        //printf("%0.2f\n", ans);
}

int main()
{
    while (~scanf("%lf%lf", &a.x, &a.y)) solve();
    return 0;
}
