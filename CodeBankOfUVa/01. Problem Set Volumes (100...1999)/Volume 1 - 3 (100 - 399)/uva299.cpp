/****
	*@PoloShen
	*Title:UVaOJ 299
	*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 50;

int train[MaxN];

void solve(){
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; i++)
		scanf("%d", &train[i]);
	int sw = 0;
	for (int i = 0; i < tt; i++)
		for (int j = i; j < tt; j++)
			if (train[i] > train[j]) {
				swap(train[i], train[j]);
				sw++;
			}
	printf("Optimal train swapping takes %d swaps.\n", sw);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}