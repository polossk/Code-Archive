/**============================================================================
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :POJ 1852
#       @file         :G:\My Source Code\【ACM】训练\0624 - 基础\poj1852.cpp
#       @date         :2014/06/24 13:11
#       @algorithm    :simulation
============================================================================**/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

/*//STL
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>
*/

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

typedef long long int64;

int t;
int l, n, x;


void solve()
{
    scanf("%d%d", &l, &n);
    int maxt = 0, mint = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        updateMax(mint, min(x, l - x));
        updateMax(maxt, max(x, l - x));
    }
    printf("%d %d\n", mint, maxt);
}

int main()
{
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}