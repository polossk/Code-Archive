/****
	*@PoloShen
	*Title:UVaOJ 152
	*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 5010;

int x[MaxN], y[MaxN], z[MaxN], d[11];

int dis(int a, int b) {
	int tx = x[a] - x[b], ty = y[a] - y[b], tz = z[a] - z[b];
	return (int) sqrt(tx * tx + ty * ty + tz * tz);
}
void input(int& i){
	while (scanf("%d%d%d", &x[i], &y[i], &z[i]) && (z[i] || y[i] || z[i])) {
		i++;
	}
}
void solve(int i){
	for (int j = 0; j < i; ++j) {
		int min = 1000;
		for (int k = 0; k < i; ++k) {
			if (j == k) continue;
			int t = dis(j, k);
			if (t < min) {
				min = t;
			}
		}
		if (min >= 0 && min <= 9)
			d[min]++;
	}
	for (int j = 0; j < 10; ++j)
		printf("%4d", d[j]);
	printf("\n");
}
int main() {
	int i = 0;
	input(i);
	solve(i);
	return 0;
}