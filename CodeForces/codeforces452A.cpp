// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
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

const string name[8] = {"vaporeon", "jolteon", "flareon",
                        "espeon", "umbreon", "leafeon",
                        "glaceon", "sylveon"};

int n; string s;

void solve()
{
    for (int i = 0; i < 8; i++)
    {
        if (name[i].size() != n) continue;
        bool flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '.') continue;
            if (s[j] != name[i][j]) { flag = 0; break; }
        }
        if (flag) { puts(name[i].c_str()); break; }
        else continue;
    }
}

int main()
{
    while (cin >> n >> s)
        solve();
    return 0;
}