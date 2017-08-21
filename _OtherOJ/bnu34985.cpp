/****
	*@author    Shen
	*@title     E
	*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;

const int MAXN = 11;
const int MAXM = 11;
const int Mod = 20140518;

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
        printf("n = %d, m =  %d\n", n, m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                printf("%8d", mat[i][j]);
            printf("\n");
        }
    }
};

Matrax add_mod(const Matrax& a,const Matrax& b,const int64 mod){
    Matrax ans(a.n,a.m);
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            ans.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
        }
    }
    return ans;
}

Matrax mul(const Matrax& a,const Matrax& b){
    Matrax ans(a.n, b.m);
    for (int i = 0; i < a.n; i++){
        for (int k = 0; k < a.m; k++){ // cache opt
            int64 tmp = 0;
            for (int j = 0; j < b.m; j++){
                tmp += a.mat[i][k] * b.mat[k][j];
            }
            ans.mat[i][j] = tmp;
        }
    }
    return ans;
}

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
    p = a; ans.Unit(a.n);
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

int64 n;
int  k, t, tt;

void solve(){
    cin >> n >> k;
    Matrax ans(k, 1);

    //tmp = cef ^ (n - 1);
    //ans = tmp * beg;
    //res = ans.mat[0][0];

    Matrax cef(k, k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= i; j++)
            cef.mat[i][j] = 1;
    for (int i = 0; i < k - 1; i++)
        cef.mat[i][i + 1] = k - i;
    //cef.print();

    Matrax beg(k, 1);
    for (int i = 0; i < k; i++)
        beg.mat[i][0] = k + 1;

    Matrax tmp(k, k);
    tmp = pow_mod(cef, n - 1, Mod);
    //tmp.print();

    ans = mul_mod(tmp, beg, Mod);
    int res = ans.mat[0][0];
    printf("Case #%d: %d\n", ++tt, res);
}

int main(){
    cin >> t;
    while (t--) solve();
    return 0;
}