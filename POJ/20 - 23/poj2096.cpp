#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

const int MaxN = 1010;
double dp[MaxN][MaxN];

int main()
{
	int n, s;
	while (cin >> n >> s)
	{
		dp[n][s]=0;
		for (int i = n; i >= 0; i--)
			for (int j = s; j >= 0; j--)
		{
			if (i == n && j == s) continue;
			dp[i][j] = i * (s - j) * dp[i][j + 1]
					+ (n - i) * j * dp[i + 1][j]
					+ (n - i) * (s - j) * dp[i + 1][j + 1]
					+ n * s;
			dp[i][j] /= (n * s - i * j);
		}
		printf("%.4lf\n", dp[0][0]);
	}
	return 0;
}
