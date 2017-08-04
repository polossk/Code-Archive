// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 5017                                                 *
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

const double r = 0.99;
const double eps = 1e-12;
const double inf = 1e+60;
const double dx[] = { 0,  0,  1, -1,  1, -1,  1, -1};
const double dy[] = { 1, -1,  0,  0, -1,  1,  1, -1};
double a, b, c, d, e, f;

inline double dis(double x, double y, double z)
{
    return sqrt(x * x + y * y + z * z);
}

double getZ(double x, double y)
{
    double A = c, B = e * x + d * y;
    double C = a * x * x + b * y * y + f * x * y - 1;
    double delta = B * B - 4.0 * A * C;
    if (delta < 0) return inf;
    double z1 = (-B + sqrt(delta)) / 2 / A;
    double z2 = (-B - sqrt(delta)) / 2 / A;
    if (z1 * z1 < z2 * z2) return z1;
    else return z2;
}

double SA()
{
    double step = 1.0;
    double x = 0.0, y = 0.0, z = 0.0;
    while (step > eps)
    {
        z = getZ(x, y);
        for (int i = 0; i < 8; i++)
        {
            double nx = x + dx[i] * step;
            double ny = y + dy[i] * step;
            double nz = getZ(nx, ny);
            if (nz > 1e30) continue;
            if (dis(nx, ny, nz) < dis(x, y, z))
            {
                x = nx; y = ny; z = nz;
            }
        }
        step *= r;
    }
    return dis(x, y, z);
}

void solve()
{
    printf("%.8lf\n", SA());
}

int main()
{
    while (~scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f))
        solve();
    return 0;
}
