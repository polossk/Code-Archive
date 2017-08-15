/****
	*@PoloShen
	*Title:Codeforces Round #224 (Div. 2) B
	*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int64;

int64 a,b,w,x,c;

int64 solve(){
	if (c <= a) return 0;
	else {
		int64  det = c - a;
		double upp = det * x - b;
		double dow = w - x;
		int64  lam = (int64)ceil(upp / dow);
		return lam + det;
	}
}

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &a, &b, &w, &x, &c);
	printf("%I64d\n", solve());
	return 0;
}