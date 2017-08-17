// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   B
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

const int MaxN = 100005;
int n, a[MaxN];
bool isInc[MaxN];
void solve()
{
    int flag = 1, sz = 0;
    // 0:表示多个增区间，输出-1
    // 1:表示一个增区间，输出0
    // 2:表示两个增区间，输出第一个增区间的长度
    scanf("%d", &a[0]);
    isInc[0] = 0;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
        isInc[i] = (a[i] >= a[i - 1]);
        if (flag == 1)
        {
            if (isInc[i]) flag = 1;
            else flag = 2, sz = i;
        }
        else if (flag == 2)
        {
            if (isInc[i]) flag = 2;
            else flag = 0, sz = 0;
        }
        else if (flag == 0) continue;
        else continue;
    }
    if (flag == 1)
        puts("0");
    else if (flag == 0)
        puts("-1");
    else if (flag == 2)
    {
        int al = a[0], ar = a[sz];
        int bl = a[sz + 1], br = a[n - 1];
        if (al >= br) printf("%d\n", n - sz);
        else puts("-1");
    }
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}