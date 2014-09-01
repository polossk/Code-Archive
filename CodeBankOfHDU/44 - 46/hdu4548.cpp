// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   C                                                        *
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

const int MaxN = 1000005;
bool isPrime[MaxN];
int sum[MaxN];
int tot, prime[MaxN];

void make_prime()
{
    fill(isPrime, isPrime + MaxN, true);
    isPrime[0] = isPrime[1] = 0;
    int tot = 0;
    for (int i = 2; i < MaxN; i++)
    {
        if (isPrime[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] >= MaxN) break;
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

inline bool judge(int x)
{
    int sum = 0;
    while (x != 0) sum += x % 10, x /= 10;
    return isPrime[sum];
}

void make_table()
{
    sum[0] = sum[1] = 0;
    for (int i = 2; i < MaxN; i++)
    {
        if (isPrime[i]) sum[i] = sum[i - 1] + judge(i);
        else sum[i] = sum[i - 1];
    }
}

int t, tt, l, r;

void solve()
{
    l = nextInt(); r = nextInt();
    printf("Case #%d: %d\n", ++tt, sum[r] - sum[l - 1]);
}

int main()
{
    make_prime();
    make_table();
    t = nextInt(); while (t--) solve();
    return 0;
}
