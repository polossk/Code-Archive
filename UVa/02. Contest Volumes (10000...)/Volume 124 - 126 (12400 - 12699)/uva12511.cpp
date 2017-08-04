/****
	*@PoloShen
	*Title:D
	*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 1010;

void solve(){
    int n, m, max = 0;
    int num1[maxN], num2[maxN];
    int dp[maxN];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&num1[i]);
    scanf("%d",&m);
    for (int i = 0; i < m; i++) scanf("%d",&num2[i]);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(num1[i] > num2[j] && max < dp[j])
                max = dp[j];
            if(num1[i] == num2[j])
                dp[j] = max + 1;
        }
        max = 0;
    }
    for (int i = 0; i < m; i++)
        max = (max > dp[i])? max: dp[i];
    printf("%d\n",max);
}

int main(){
	int T; cin >> T;
	while (T--) solve();
}