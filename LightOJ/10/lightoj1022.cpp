// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   LightOJ 1022
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
int t, tt;
double r, s;

void solve()
{
    scanf("%lf", &r);
    s = (4.0 - pi) * r * r;
    printf("Case %d: %.2lf\n", ++tt, s);
}

int main()
{
    scanf("%d", &t); while (t--) solve();
    return 0;
}
