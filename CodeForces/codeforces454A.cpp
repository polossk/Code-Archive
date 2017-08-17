// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   A
******************************************************************************/

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
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

int n;

inline void putc_s(int n) { while (n--) putchar('*'); }
inline void putc_d(int n) { while (n--) putchar('D'); }


void solve()
{
    int i = 1, j = n;
    for (i = 1; i < j; i += 2)
    {
        putc_s((j - i) / 2);
        putc_d(i);
        putc_s((j - i) / 2);
        puts("");
    }
    for (i = j; i >= 1; i -= 2)
    {
        putc_s((j - i) / 2);
        putc_d(i);
        putc_s((j - i) / 2);
        puts("");
    }
}

int main()
{
    while (cin >> n)
        solve();
    return 0;
}