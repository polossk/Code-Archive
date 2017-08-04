// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   LightOJ 1015
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int t, tt, n, d, sum;

void solve()
{
    for (scanf("%d", &n), d = 0, sum = 0; n > 0; n--, sum += (d > 0)? d: 0)
        scanf("%d", &d);
    printf("Case %d: %d\n", ++tt, sum);
}

int main()
{
    scanf("%d", &t); while (t--) solve();
    return 0;
}
