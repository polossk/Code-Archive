// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   D                                                        *
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

const int MAXN = 2;
const int MAXM = 2;
const int Mod = 1000000007;

struct Matrax{
    int n,m;
    int64 mat[MAXN][MAXM];
    Matrax():n(-1),m(-1){}
    Matrax(int _n,int _m):n(_n),m(_m){
        memset(mat,0,sizeof(mat));
    }
    void Unit(int _s){
        n=_s; m=_s;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = (i == j)? 1: 0;
            }
        }
    }
    void print(){
        cout << n << ", " << m << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << " " << mat[i][j];
            }
            cout << endl;
        }
    }
};

Matrax mul_mod(const Matrax& a, const Matrax& b, const int mod){
    Matrax ans(a.n, b.m);
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < b.m; j++){
            int64 tmp = 0;
            for (int k = 0; k < a.m; k++){
                tmp += (a.mat[i][k] * b.mat[k][j]) % mod;
            }
            ans.mat[i][j] = tmp % mod;
        }
    }
    return ans;
}

Matrax pow_mod(const Matrax& a, int64 k, const int mod){
    Matrax p(a.n,a.m), ans(a.n,a.m);
    p = a; ans = a;
    ans.Unit(a.n);
    if (k==0) return ans;
    else if (k==1) return a;
    else {
        while (k){
            if (k & 1){
                ans=mul_mod(ans, p, mod);
                k--;
            }
            else {
                k /= 2;
                p = mul_mod(p, p, mod);
            }
        }
        return ans;
    }
}

int64 q_mul_mod(int64 a,int64 b,int64 m = Mod){
    a %= m; b %= m;
    int64 t = 0;
    while (b){
        if (b & 1){
            t += a;
            if (t>=m) t -= m;
        }
        a <<= 1;
        if (a >= m) a -= m;
        b >>= 1;
    }
    return t;
}

int64 q_pow_mod(int64 a, int64 b, int64 m = Mod){
    int64 ans = 1;
    a %= m;
    while (b){
        if (b & 1){
            ans = q_mul_mod(ans, a, m);
            b--;
        }
        b /= 2;
        a = q_mul_mod(a, a, m);
    }
    return ans;
}

int64 a, b, n;

void solve()
{
    Matrax beg(2, 2);
    beg.mat[0][0] = 0; beg.mat[0][1] = 1;
    beg.mat[1][0] = 1; beg.mat[1][1] = 1;

    Matrax tmp(2, 2);
    tmp = pow_mod(beg, n, Mod - 1);

    int64 A = q_pow_mod(a, tmp.mat[0][0]) % Mod;
    int64 B = q_pow_mod(b, tmp.mat[0][1]) % Mod;
    int64 ans = A * B  % Mod;
    cout << ans << endl;
    return;
}

int main()
{
    while (cin >> a >> b >> n) solve();
    return 0;
}
