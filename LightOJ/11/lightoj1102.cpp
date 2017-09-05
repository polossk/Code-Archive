// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   lightoj 1102                                             *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

int64 gcd_ex(int64 a, int64 b, int64& x, int64& y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    int64 d = gcd_ex(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}
// ax = b (mod m)
// @if (return == m) => No solusion
// ax = b (mod m), all x in [0, m)
// returning empty vector<int64> when no solusion
vector<int64> solve(int64 a, int64 b, int64 m)
{
	int64 x, y; int64 d = gcd_ex(a, m, x, y);
	vector<int64> ans; ans.clear();
	if (b % d == 0)
	{
		x %= m; while (x < 0) x += m; x %= m;
		ans.push_back(x * (b / d) % (m / d));
		for (int64 i = 1; i < d; i++)
			ans.push_back((ans[0] + i * m / d) % m);
	}
	return ans;
}


int64 CRT(int64 a[],int64 m[],int64 n)
{
	int64 M = 1, res = 0;
    for (int i = 0; i < n; i++) M *= m[i];
	for (int i = 0; i < n; i++)
	{
		int64 x, y;
		int64 tm = M / m[i];
		gcd_ex(tm, m[i], x, y);
		res = (res + tm * x * a[i]) % M;
	}
	return (res + M) % M;
}

int64 mul_mod(int64 a, int64 b, int64 m)
{
	int64 t = 0; a %= m; b %= m;
	while (b)
	{
		if (b & 1) t += a, t %= m;
		a <<= 1; a %= m; b >>= 1;
	}
	return t;
}

int64 pow_mod(int64 a, int64 b, int64 m)
{
	int64 ans = 1; a %= m;
	while (b)
	{
		if (b & 1) { ans = mul_mod(ans, a, m); b--; }
		b >>= 1; a = mul_mod(a, a, m);
	}
	return ans;
}

const int MaxM = 2000005;
const int64 MOD = 1000000007;
int64 fac[MaxM]; // fact, 1 * 2 * 3 * ...
void init()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i < MaxM; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
}

int64 c(int64 n, int64 k)
{
	int64 x = 0, y = 0;
	int64 tmp = mul_mod(fac[k], fac[n - k], MOD);
	gcd_ex(tmp, MOD, x, y);
	x = (x % MOD + MOD) % MOD;
	return mul_mod(fac[n], x, MOD);
}

int64 Lucas(int64 n, int64 k)
{
	if (k == 0) return 1;
	int64 t1 = c(n % MOD, k % MOD);
	int64 t2 = Lucas(n / MOD, k / MOD);
	return t1 * t2 % MOD;
}
int64 N,M;



//本题的主要求解
int64 solve(int64 n,int64 k){
	if (k==1){
		return 1;
	}
	else if (n==0){
		return 1;
	}
	else return Lucas(n+k-1,k-1);
}

int main (){
	int T,tt=1;
	int64 n,k;init();
	cin>>T;
	while (T--){
		cin>>n>>k;
		int64 ans;
		ans=solve(n,k);
		cout<<"Case "<<tt++<<": "<<ans<<endl;
	}
	return 0;
}
