/**============================================================================
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :POJ 3617
#       @file         :G:\My Source Code\【ACM】训练\0624 - 基础\poj3617.cpp
#       @date         :2014/06/24 13:46
#       @algorithm    :Greedy
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

typedef long long int64;

int n;
char t[2005], s[2005];

void solve()
{
    for (int i = 0; i < n; i++)
        scanf(" %c", &t[i]);
    int i = 0, j = n - 1;
    for (int k = 0; k < n; k++)
    {
        if (t[i] > t[j]) s[k] = t[j--];
        else if (t[i] < t[j]) s[k] = t[i++];
        else
        {
            int it = i, jt = j;
            bool flag = 0;
            while (t[it] == t[jt] && it <= jt) it++, jt--;
            flag = (t[it] < t[jt]);
            if (flag) s[k] = t[i++];
            else s[k] = t[j--];
        }
    }
    for (int i = 0; i < n; i++)
    {
	printf("%c", s[i]);
	if (i % 80 == 79) printf("\n");
    }
    if (n % 80) printf("\n");
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}