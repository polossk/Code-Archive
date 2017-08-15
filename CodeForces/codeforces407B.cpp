/****
	*@author    Shen
	*@title     d
	*/

#include <iostream>
#include <cstdio>
using namespace std;

const int Mod = 1000000007;
int p[1005], dp[1005];
int n;

void solve(){
    int r = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 2;
        for(int j = p[i]; j < i; j++) dp[i] += dp[j], dp[i] %= Mod;
        r += dp[i], r %= Mod;
    }
    printf("%d\n", r);
}

int main(){
    while (cin >> n) solve();
    return 0;
}
