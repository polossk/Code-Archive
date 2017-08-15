// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author:	Shen
*@name	:	C
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

void solve()
{
    int64 n, k, d1, d2;
    bool ans = 0;
    cin >> n >> k >> d1 >> d2;
    if (k < max(d1, d2)) puts("no");
    else
    {
		int64 t1 = k - d1 + d2;
		int64 t2 = k + d1 - d2;
		int64 t3 = k + d1 + d2;
		int64 t4 = k - d1 - d2;
		int64 dmx = max(d1, d2), det = abs(d1 - d2);
        if (t1 % 3 == 0 && t1 / 3 >= d2)
        {
            if ((n -  d1 - t3) >= 0 && (n -  d1 - t3) % 3 == 0)
                ans = 1;
        }
        if (t2 % 3 == 0 && t2 / 3 >= d1)
        {
            if ((n -  d2 - t3) >= 0 && (n -  d2 - t3) % 3 == 0)
                ans = 1;
        }
        if (t4 % 3 == 0 && t4 >= 0)
        {
            int x = t1 / 3;
            if ((n - k - dmx - det) >= 0 && (n - k - dmx - det) % 3 == 0)
                ans = 1;
        }
        if (t3 % 3 == 0 && t3 / 3 - max(d1, d2) >= 0)
        {
            int x = t1 / 3;
            if ((n - t3) >= 0 && (n - t3) % 3 == 0)
                ans = 1;
        }
        if (ans == 1) puts("yes");
        else puts("no");
    }
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
