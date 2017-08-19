// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #391 Div. 1 + Div. 2, combined B                         *
*****************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

const int MAXN = 100000;
const int MAXS = 100000;

bool isPrime[MAXN];
int tot, prime[MAXN], cnt[MAXN];
map<int, int> idx;

void getPrime()
{
	fill(isPrime, isPrime + MAXN, true);
	isPrime[0] = isPrime[1] = 0; tot = 0;
	for (int i = 2; i < MAXN; i++)
	{
		if (isPrime[i]) { prime[tot] = i; idx[i] = tot; tot++; }
		for (int j = 0; j < tot; j++)
		{
			if (i * prime[j] >= MAXN) break;
			isPrime[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
}

void factor(int n)
{
	for (int i = 0; i < tot; i++)
	{
		if (n < prime[i] * prime[i]) break;
		if (n % prime[i] == 0)
		{
			cnt[i]++;
			while (n % prime[i] == 0) n /= prime[i];
		}
	}
	if (n > 1) cnt[idx[n]]++;
}

int main()
{
	getPrime();
	int n = nextInt();
	for (int i = 0; i < n; i++) factor(nextInt());
	if (n == 1) { puts("1"); return 0; }
	int ans = 1;
	for (int i = 0; i < tot; i++) updateMax(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}