/****
	*@PoloShen
	*Title:UVa 10025
	*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int64;

void inequality(double a, double b, double c,int64& x){
    x = 0;
    double d = b * b - 4 * a * c;
    if (d < 0) return;
    else{
        d = sqrt(d);
        double y = (-b + d) / (2 * a);
        x = floor(y);
        return;
    }
}

inline int64 minEve(int64 m){ return 8 * m * m + 2 * m + 2; }
inline int64 maxEve(int64 m){ return 8 * m * m + 18 * m + 10; }
inline int64 minOdd(int64 m){ return 8 * m * m - 6 * m + 1; }
inline int64 maxOdd(int64 m){ return 8 * m * m + 10 * m + 3; }
inline int64 maxNum(int64 m){ return (m + 1) * m / 2; }

int64 queryOdd(int64 n){
    int64 x1 = 0, x2 = 0;
    inequality(8, -6, 1-n, x2);
    inequality(8, 10, 3-n, x1);
    int64 i = x1, m = x1;
    int64 mi = 0, ma = 0;
    for (int64 i = x1; i <= x2; i++){
        mi = minOdd(i); ma = maxOdd(i);
        if (mi <= n && n <= ma) { m = i;break; }
    }
    int64 mid = maxNum(4 * m + 1);
    return (mid < n && n <= ma)? 4 * m + 2: 4 * m + 1;
}
int64 queryEve(int64 n){
    int64 x1 = 0, x2 = 0;
    inequality(8, 2, 2-n, x2);
    inequality(8, 18, 10-n, x1);
    int64 i = x1, m = x1;
    int64 mi = 0, ma = 0;
    for (int64 i = x1; i <= x2; i++){
        mi = minEve(i); ma = maxEve(i);
        if (mi <= n && n <= ma) { m = i;break; }
    }
    int64 mid = maxNum(4 * m + 3);
    return (mid < n && n <= ma)? 4 * m + 4: 4 * m + 3;
}
inline int64 Abs(int64 a){ return (a < 0)? -a: a; }

void solve(){
    int64 n, k; cin >> n;
    if (n == 0) { cout << 3 << endl; return; }
    n = Abs(n);
    if (n % 2) k = queryOdd(n);
    else k = queryEve(n);
    cout << k << endl;
}

int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out", "w", stdout);
    int T; cin >> T;
    int tt = 0;
    while (T--){
        if (tt > 0) cout << endl;
        solve(); tt++;
    }
    return 0;
}