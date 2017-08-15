// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:	A
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

int n, m;
const string w = "Akshat";
const string l = "Malvika";

int main()
{
    while (cin >> n >> m)
    {
        int c = min(n, m);
        if (c % 2) cout << w << endl;
        else cout << l << endl;
    }
    return 0;
}
