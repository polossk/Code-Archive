/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author       :Shen
* @name         :[NWPU][2014][SRM][3] D
* @date         :2014/07/17 18:46
* @algorithm    :Simulation
******************************************************************************/

//#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

int t, tt, c;
string s1, s2, s12;
queue<char> q1, q2;
map<string, int> m;

string shuffle()
{
    for (int i = 0; i < c; i++)
        q1.push(s1[i]), q2.push(s2[i]);
    string res;
    for (int i = 0; i < c; i++)
    {
        res += q2.front(); q2.pop();
        res += q1.front(); q1.pop();
    }
    return res;
}

void solve()
{
    scanf("%d", &c);
    cin >> s1 >> s2 >> s12;
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    m.clear();
    int cnt = 0; bool flag = false;
    while (true)
    {
        cnt++; string s = shuffle();
        if (!m[s]) m[s]++;
        else { flag = true; break; }
        if (s == s12)
        {
            printf("%d %d\n", ++tt, cnt);
            break;
        }
        s1 = s.substr(0, c); s2 = s.substr(c, c);
    }
    if (flag) printf("%d %d\n", ++tt, -1);
}

int main()
{
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
