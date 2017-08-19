// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   #391 Div. 1 + Div. 2, combined C                         *
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

const int MAXN = 100005;
const int MAXM = 1000005;
const int MOD = 1000000007;
const int64 PRIME_A = 1004535809LL;
const int64 PRIME_B = 469762049LL;
const int64 hash_ = 10007;

int64 _1 = 1, _2 = 1;
int64 fac[MAXM];
int hash_a[MAXM], hash_b[MAXM];

void _hash(int _)
{
	hash_a[_] = (hash_a[_] + _1) % PRIME_A;
	hash_b[_] = (hash_b[_] + _2) % PRIME_B;
}

void _roll()
{
	_1 = (_1 * hash_) % PRIME_A;
	_2 = (_2 * hash_) % PRIME_B;
}

void init()
{
	fac[0] = fac[1] = 1;
	for (int i = 2; i < MAXM; i++)
		fac[i] = fac[i - 1] * i % MOD;
}


int main()
{
	init();
	int n = nextInt();
	int m = nextInt();
	for (int i = 0; i < n; i++)
	{
		int g = nextInt();
		for (int j = 0; j < g; j++)
		{
			_hash(nextInt());
		}
		_roll();
	}
	map<pair<int, int>, int> cnt;
	for (int i = 1; i <= m; i++)
		cnt[make_pair(hash_a[i], hash_b[i])]++;
	int64 ans = 1;
	for (auto elem : cnt)
	{
		ans = (ans * fac[elem.second]) % MOD;
	}
	cout << ans << endl;
	return 0;
}