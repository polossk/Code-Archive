/****
	*@author    Shen
	*@title     C
	*/

#include <cstdio>
using namespace std;

int n;
int XOR[1000005];

void solve()
{
    int ans, tmp;
    scanf("%d", &tmp);
    ans = tmp;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d",&tmp);
        ans ^= tmp;
    }
    for (int i = 2; i <= n; i++){
        int seg = n / i;
        if (seg & 1 == 1) ans ^= XOR[i - 1];
        ans ^= XOR[n % i];
    }
    printf("%d\n",ans);
}

int main()
{
    XOR[0] = 0;
    for (int i = 1; i < 1000005; i++)
        XOR[i] = XOR[i - 1] ^ i;
    while (~scanf("%d", &n))
        solve();
    return 0;
}
