/****
	*@PoloShen
	*Title:UVa 107
	*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int64;

const int64  inf = 10000000;
const double eps = 0.00001;
int64 A, B;
int64 ans1, ans2;

template <typename Tp>
inline int64 sgn(Tp a){
    return (a > eps)? 1: ( (a < -eps)? -1: 0 );
}

inline double F(int64 n){
    return log(A) * log(n) - log(B) * log(n+1);
}

int64 getN(){
    int64 l = 1, r = inf;
    int64 m = 0;
    while (r > l){
        m = (r - l) / 2 + l;
        int64 sgnm = sgn(F(m));
        if (sgnm == 0) break;
        else{
            if (sgnm == 1) r = m;
            else l = m;
        }
    }
    return m;
}

void solve(){
    int64 N = getN();
    int64 a = A, b = 1, c = 0;
    ans1 = ans2 = 0;
    while (1){
        c = a * b;
        ans1 += b;
        ans2 += c;
        if (a == 1) break;
        a /= (N+1);
        b *= N;
    }
    ans1 -= B;
    cout << ans1 << ' ' << ans2 << endl;
}

int main(){
    while (cin >> A >> B){
        if (A == 0 && B == 0) break;
        else solve();
    }
    return 0;
}