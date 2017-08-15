// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:	D
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

typedef long long int64;

const int MaxN = 100005;
char str[MaxN];
int a[7][7];

void solve()
{
    int len = strlen(str + 1);
    int64 x = 0, y = 0;
    for(int i = 1; i <= len; i++)
    {
        a[i & 1][str[i] - 'a']++;
        y += a[i & 1][str[i] - 'a'];
        x += a[!(i & 1)][str[i] - 'a'];
    }
    printf("%I64d %I64d\n", x, y);
}

int main()
{
    while (~scanf("%s", str + 1)) solve();
    return 0;
}
