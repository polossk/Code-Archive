// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   C
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

int main()
{
    double m,n;
    cin >> m >> n;
    double ans = m;
    for(int i = 1; i <= m; i++)
        ans -= pow((i - 1) * 1.0 / (m), n);
    printf("%.4lf\n", ans);
    return 0;
}