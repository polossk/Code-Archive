// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   LightOJ 1042
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
inline int    nextInt() { int x; scanf("%d", &x); return x; }
int t, tt, n, ans;

void solve()
{
    unsigned long v = (unsigned long)nextInt();
    bitset<32> bin(v);
    for (int i = 0; i < 31; i++) if (bin[i] && !bin[i + 1])
    {
        bin.flip(i); bin.flip(i + 1);
        bitset<32> tmp(0x0000);
        for (int j = 0, k = 0; j < i; j++) if (bin[j]) tmp[k++] = 1;
        for (int j = 0; j < i; j++) bin[j] = tmp[j];
        break;
    }
    ans = (int)bin.to_ulong();
    printf("Case %d: %d\n", ++tt, ans);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
