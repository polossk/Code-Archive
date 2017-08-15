/****
	*@PoloShen
	*Title:D
	*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long int64;
const int sz = 45;
int t[sz][sz];
int64 dp[sz][sz][sz][sz];

int64 getDP(int n, int from, int via, int to)
{
    if (n==1) return min(t[from][to], t[from][via] + t[via][to]);
    int64& ret = dp[n][from][via][to];
    if(ret != -1) return ret;
    ret = getDP(n-1, from, to, via) + getDP(n-1, via, from, to) + t[from][to];
    ret = min(ret, 2 * getDP(n-1, from, via, to) + t[from][via] + getDP(n-1, to, via, from) + t[via][to]);
    return ret;
}

int main()
{
    int n, m;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &t[i][j]);
    scanf("%d", &n);
    cout << getDP(n, 0, 1, 2) << endl;
    return 0;
}