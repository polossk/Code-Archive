/****
	*@PoloShen
	*Title:UVa 111
	*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 25;
int correct[MAXN], query[MAXN];
int dp[MAXN][MAXN];

void build(int n){
    int x;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        correct[x] = i;
    }
}

void solve(int x, int n){
    query[x] = 1;
    for (int i = 2; i <= n; i++){
        scanf("%d", &x);
        query[x] = i;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (correct[i] == query[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    printf("%d\n", dp[n][n]);
}

int main(){
    int n, x; scanf("%d", &n);
    build(n);
    while (scanf("%d", &x) != EOF){
        solve(x, n);
    }
    return 0;
}