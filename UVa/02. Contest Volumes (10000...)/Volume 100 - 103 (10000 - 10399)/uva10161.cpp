/****
	*@PoloShen
	*Title:UVa 10161
	*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void solve(int n){
    int k = floor(sqrt(double(n)));
    if (k * k == n){
        if (k&1) printf("%d %d\n", 1, k);
        else printf("%d %d\n", k, 1);
    } else {
        int t = n - k * k;
        int m = t % (k + 1);
        if (k & 1){
            if (t <= k + 1) printf("%d %d\n", t, k + 1);
            else printf("%d %d\n", k + 1, k + 1 - m);
        } else {
            if (t <= k + 1) printf("%d %d\n", k + 1, t);
            else printf("%d %d\n", k + 1 - m, k + 1);
        }
    }
}

int main(){
    int n = 0;
    while (cin >> n && n) solve(n);
    return 0;
}