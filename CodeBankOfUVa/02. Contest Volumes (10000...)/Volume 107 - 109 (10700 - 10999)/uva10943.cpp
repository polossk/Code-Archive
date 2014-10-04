#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
const double pi=acos(-1.0);
const int N=105;
const int mod=1000000;
int dp[N][N];
int main()
{
    for(int i=0;i<=100;i++)
        dp[0][i]=dp[i][1]=1;
    for(int i=1;i<=100;i++)
    {
        for(int j=2;j<=100;j++)
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
    int n,k;
    while(cin>>n>>k)
    {
        if(n==0&&k==0) break;
        cout<<dp[n][k]<<endl;
    }
    return 0;
}