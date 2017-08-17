// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   D
******************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker,  "/STACK:1024000000, 1024000000")

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a,  T b){ return a > b ? a  =  b,  1: 0; }
template<class T>inline bool updateMax(T& a,  T b){ return a < b ? a  =  b,  1: 0; }

const int INF = 0x7fffffff;
const int S  =  1 << 17;
int n, p[30], num = 0;
int ans[105], pre[105][1 << 17];
int son[105], d[105][1 << 17];
int a[105];

bool prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void dfs(int i, int j) {
    if (i == 0) return;
    else
    {
        ans[i] = pre[i][j];
        dfs(i - 1, j ^ son[pre[i][j]]);
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        num = 0;
    memset(pre, -1, sizeof(pre));
    for (int i = 1;i <= 60; i++)
        if (prime(i)) p[num++] = i;
    for (int i = 0;i <= n; i++)
        for (int j = 0; j < S; j++)
            d[i][j] = INF;
    for (int i = 1; i < 60; i++)
        for (int j = 0; j < num; j++)
            if (i % p[j] == 0)
                son[i] |= 1 << j;
    d[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < S; j++)
            if (d[i][j] != INF)
            {
                for (int k  =  1; k < 60; k++)
                if ((son[k] & j) == 0)
                {
                    if (d[i + 1][son[k] | j] >= d[i][j] + abs(a[i] - k))
                    {
                        d[i + 1][son[k] | j]  =  d[i][j] + abs(a[i] - k);
                        pre[i + 1][son[k] | j]  =  k;
                    }
                }
            }
    int ansv = INF, ansj;
    for (int j  =  0; j < S; ++j)
        if (d[n][j] <= ansv)
    {
        ansv  =  d[n][j];
        ansj  =  j;
    }
    dfs(n,  ansj);
    for (int i = 1;i<= n;i++)
    {
        if (i > 1) putchar(' ');
        printf("%d", ans[i]);
    }
	puts("");
	return 0;
}