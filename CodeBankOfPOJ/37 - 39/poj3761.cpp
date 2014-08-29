#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int64;

const int MaxL = 1000001;
const int64 mod = 20100713LL;
int64 fact[MaxL];

void init()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i < MaxL; i++)
		fact[i] = fact[i - 1] * i % mod;
}

int64 pow_mod(int64 a, int64 b, const int64& m)
{
	int64 ans = 1; a %= m;
	while (b)
	{
		if (b & 1) { ans = ans * a % m; b--; }
		b >>= 1; a = a * a % m;
	}
	return ans;
}

int main()
{
	int t; int64 n, k;
	int64 ans1, ans2, ans;
	init(); scanf("%d", &t);
	while (t--)
	{
		scanf("%I64d%I64d", &n, &k);
		if (k == 0) { printf("1\n"); continue; }
		ans1 = ans2 = fact[k];
		ans1 *= pow_mod(k + 1, n - k, mod);
		ans1 %= mod;
		ans1 += mod;
		ans2 *= pow_mod(k, n - k, mod);
		ans2 %= mod;
		ans = (ans1 - ans2) % mod;
		printf("%I64d\n",ans);
	}
	return 0;
}