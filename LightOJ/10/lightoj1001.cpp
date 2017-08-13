// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   LightOJ 1001
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
inline int    nextInt() { int x; scanf("%d", &x); return x; }
int t, a, b;
int main(){
    t = nextInt();
    while (t--)
    {
		a = nextInt();
		b = (a > 10)? a - 10: 0; a = a - b;
		printf("%d %d\n", a, b);
    }
    return 0;
}
