// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   LightOJ 1000
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
inline int    nextInt() { int x; scanf("%d", &x); return x; }
int t, tt, a, b;
int main(){
    t = nextInt();
    while (t--)
    {
		a = nextInt(); b = nextInt();
		printf("Case %d: %d\n", ++tt, a + b);
    }
    return 0;
}
