/****
	*@author    Shen
	*@title     HDU 2604
	*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;

const int MAXN = 4;
const int MAXM = 4;
const int Mod = 1000000007;

struct Matrax{
    int n, m;
    int64 mat[MAXN][MAXM];
    Matrax(): n(-1), m(-1){}
    Matrax(int _n, int _m): n(_n), m(_m){
        memset(mat, 0, sizeof(mat));
    }
    void Unit(int _s){
        n = _s; m = _s;
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
                printf("%16d", mat[i][j]);
            printf("\n");
        }
    }
};

Matrax add_mod(const Matrax& a,const Matrax& b,const int64 mod){
    Matrax ans(a.n, a.m);
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
        for (int j = 0; j < b.m; j++){
            int64 tmp = 0;
            for (int k = 0; k < a.m; k++){
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
    Matrax p(a.n, a.m), ans(a.n, a.m);
    p = a; ans.Unit(a.n);
    if (k == 0) return ans;
    else if (k == 1) return a;
    else {
        while (k){
            if (k & 1){
                ans = mul_mod(ans, p, mod);
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

int  l, m;

void solve(){
    if (l <= 2)
    {
        int root = 1;
        for (int i = 0; i < l; i++)
            root *= 2;
        cout << root % m << endl;
        return;
    }

    Matrax ans(1, 1);

    //tmp = cef ^ (l - 2);
    //ans = vct * tmp;
    //ans = ans * beg;
    //res = ans.mat[0][0] % m;

    Matrax cef(4, 4), tmp(4, 4);
    cef.mat[0][0] = 1; cef.mat[0][3] = 1;
    cef.mat[1][2] = 1;
    cef.mat[2][0] = 1;
    cef.mat[3][1] = 1; cef.mat[3][2] = 1;
    //cef.print();

    Matrax beg(4, 1), vct(1, 4);
    for (int i = 0; i < 4; i++)
        beg.mat[i][0] = vct.mat[0][i] = 1;

    tmp = pow_mod(cef, l - 2, m);
    //tmp.print();

    vct = mul_mod(vct, tmp, m);
    ans = mul_mod(vct, beg, m);
    //ans.print();

    int res = ans.mat[0][0];
    cout << res % m << endl;
}

int main(){
    while (cin >> l >> m) solve();
    return 0;
}
