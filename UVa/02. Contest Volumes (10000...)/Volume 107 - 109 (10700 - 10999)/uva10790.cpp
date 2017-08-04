/****
	*@PoloShen
	*Title:uva 10790
	*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long int64;
int64 a, b;

void solve(int tt){
    int64 sumA = a * (a - 1);
    sumA >>= 1;
    int64 sumB = b * (b - 1);
    sumB >>= 1;
    printf("Case %d: %lld\n", tt, sumA * sumB);
}

int main(){
    int tt = 0;
    while (cin >> a >> b && a && b) solve(++tt);
    return 0;
}