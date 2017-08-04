// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4497                                                 *
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
#include <limits>
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

const int maxN = 100005;
int a[maxN], b[maxN];
int G, L;

void factor(int n, int& tot){
    int temp,i;
    tot =-1;
    for (int i = 2; i * i <= n; ++i){
        if (n%i == 0){
            a[++tot] = i;
            b[tot] = 0;
            while (n % i == 0){
                ++b[tot];
                n /= i;
            }
        }
    }
    if (n != 1){
        a[++tot] = n;
        b[tot] = 1;
    }
}
void solve(){
    scanf("%d%d",&G,&L);
    if (L % G != 0){ printf("0\n"); return; }
    L = L / G;
    int tot;
    factor(L, tot);
    long long ans = 1;
    for (int i = 0; i <= tot; ++i) ans *= (6 * b[i]);
    printf("%I64d\n",ans);
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}