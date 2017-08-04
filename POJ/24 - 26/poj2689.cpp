#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

const int MaxN = 50001;
const int INF  = 0x3f3f3f3f;

typedef long long int64;

int prime1[MaxN], nprime1;
bool isprime[MaxN * 20];
void make_prime1()
{
	nprime1 = 0;
	fill(isprime, isprime + MaxN * 20, 1);
	for (int64 i = 2; i < MaxN; i++) if (isprime[i])
	{
		prime1[++nprime1]=i;
		for (int64 j = i * i; j < MaxN; j += i) isprime[j] = 0;
	}
}
int64 l, u;
int64 prime2[1000001];
int nprime2;
void make_prime2()
{
	fill(isprime, isprime + MaxN * 20, 1);
	for (int64 i = 1; i <= nprime1; i++)
	{
		int64 b = l / prime1[i];
		while (b * prime1[i] < l || b <= 1) b++;
		for (int64 j = b * prime1[i]; j <= u; j += prime1[i])
			if (j >= l) isprime[j - l] = 0;
	}
	if (l == 1) isprime[0] = 0;
}
void solve()
{
	int64 min = INF, max = -INF;
	int64 minl, minr, maxl, maxr;
	make_prime2(); nprime2 = 0;
	for (int i = 0; i <= u - l; i++) if (isprime[i])
		prime2[++nprime2] = i + l;
	if (nprime2 <= 1) puts("There are no adjacent primes.");
	else{
		for (int i = 1; i < nprime2; i++)
		{
			if (prime2[i + 1] - prime2[i] < min)
			{
				min = prime2[i + 1] - prime2[i];
				minl = prime2[i]; minr = prime2[i + 1];
			}
			if (prime2[i + 1] - prime2[i] > max)
			{
				max = prime2[i + 1] - prime2[i];
				maxl = prime2[i]; maxr = prime2[i + 1];
			}
		}
		printf("%I64d,%I64d are closest, ", minl, minr);
		printf("%I64d,%I64d are most distant.\n", maxl, maxr);
	}
}
int main()
{
	make_prime1();
	while (~scanf("%I64d%I64d", &l, &u)) solve();
	return 0;
}
