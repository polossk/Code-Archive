// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4423                                                 *
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
#include <limits>
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

int dcmp(double d)
{
    if (d > EPS)
        return 1;
    else if (d < -EPS)
        return -1;
    else
        return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int A, B, C, D, E;
        scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);

        B = B - A*D;
        C = C - A*E;
        double AA = A;

        if (B == 0)
        {// g(x)=C/(x^2+Dx+E)
            if (C == 0)
                printf("[%.4f, %.4f]\n", AA, AA);
            else
            {
                double m = -D*D/4.0 + E;
                if (dcmp(m) > 0)
                {// det<0
                    if (C > 0)
                        printf("(%.4f, %.4f]\n", AA, C / m + AA);
                    else
                        printf("[%.4f, %.4f)\n", C / m + AA, AA);
                }
                else if (dcmp(m) == 0)
                {// det==0
                    if (C > 0)
                        printf("(%.4f, INF)\n", AA);
                    else
                        printf("(-INF, %.4f)\n", AA);
                }
                else
                {// det>0
                    if (C > 0)
                        printf("(-INF, %.4f] U (%.4f, INF)\n", C / m + AA, AA);
                    else
                        printf("(-INF, %.4f) U [%.4f, INF)\n", AA, C / m + AA);
                }
            }
        }
        else
        {//B!=0 -- g(x)=(Bx+C)/(x^2+Dx+E)
            double x1 = -1.0*C/B;
            if (dcmp(x1*x1+D*x1+E) == 0)
            {// 可以分解因式，约分 -- g(x)=B/(x-x2) 注意定义域x!=x1)
                double x2 = -D - x1;
                if (dcmp(x1-x2) == 0)//x1 == x2
                    printf("(-INF, %.4f) U (%.4f, INF)\n", AA, AA);
                else
                {
                    double py = B / (x1 - x2); //挖去一个点
                    if (dcmp(py) < 0)
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n", py+AA, py+AA, AA, AA);
                    else
                        printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n", AA, AA, py+AA, py+AA);
                }
            }
            else
            {// 不可以分解 -- 换元，分子变为x  -- g(x) = Bx/(x^2+D2x+E2) = B / (x+E2/x + D2)
                double D2 = D - 2.0*C/B;
                double E2 = 1.0*C*C/B/B - 1.0*C*D/B + E;
                if (dcmp(E2) < 0)
                    printf("(-INF, INF)\n");
                else
                {
                    double p = D2 + 2 * sqrt(E2);
                    double q = D2 - 2 * sqrt(E2);
                    if (B > 0)
                    {
                        if (dcmp(p)>0 && dcmp(q) > 0)
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/p + AA, B/q + AA);
                        else if (dcmp(q) == 0)
                            printf("(-INF, %.4f]\n", B/p + AA);
                        else if (dcmp(p)>0 && dcmp(q) < 0)
                            printf("[%.4f, %.4f]\n", B/q + AA, B/p + AA);
                        else if (dcmp(p) == 0)
                            printf("[%.4f, INF)\n", B/q + AA);
                        else
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/p + AA, B/q + AA);
                    }
                    else
                    {
                        if (dcmp(p)>0 && dcmp(q) > 0)
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/q + AA, B/p + AA);
                        else if (dcmp(q) == 0)
                            printf("[%.4f, INF)\n", B/p + AA);
                        else if (dcmp(p)>0 && dcmp(q) < 0)
                            printf("[%.4f, %.4f]\n", B/p + AA, B/q + AA);
                        else if (dcmp(p) == 0)
                            printf("(-INF, %.4f]\n", B/q + AA);
                        else
                            printf("(-INF, %.4f] U [%.4f, INF)\n", B/q + AA, B/p + AA);
                    }
                }
            }
        }
    }
    return 0;
}