#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 115;
int dp[45110][MaxN];
int w[MaxN];
int main (){
	int n,sum,r;
	while (~scanf("%d",&n))
	{
		sum = 0;
		r = (n + 1) >> 1;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&w[i]);
			sum += w[i];
		}
		memset(dp, 0, sizeof (dp));
		dp[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = sum / 2; j >= w[i]; j--)
				for (int k = r; k >= 1; k--)
					if (dp[j - w[i]][k - 1] == 1) dp[j][k] = 1;
		}
		int ans1 = 0, ans2 = 0;
		for (int i = sum / 2; i > 0; i--)
		{
			if (n % 2 == 0)
			{
				if (dp[i][r]==1)
				{
					ans1 = i, ans2 = sum - i;
					break;
				}
			}
			else
			{
				if (dp[i][r] == 1 || dp[i][r - 1] == 1)
				{
					ans1 = i, ans2 = sum - i;
					break;
				}
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
