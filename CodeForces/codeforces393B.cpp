/****
	*@PoloShen
	*Title:B
	*/
#include <iostream>
#include <cstdio>
using namespace std;

int W[200][200];
double a[200][200], b[200][200];
int n;

void solve(){
    for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
            a[i][j] = 0.5 * (W[i][j] + W[j][i]);
            b[i][j] = 0.5 * (W[i][j] - W[j][i]);
		}
    }
    for (int i=0;i<n;i++){
		for (int j=0;j<n-1;j++){
			printf("%.8lf ", a[i][j]);
		}
		printf("%.8lf\n", a[i][n-1]);
	}
    for (int i=0;i<n;i++){
		for (int j=0;j<n-1;j++){
			printf("%.8lf ", b[i][j]);
		}
		printf("%.8lf\n", b[i][n-1]);
	}
}

int main(){
    cin >> n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>W[i][j];
		}
	}
    solve();
    return 0;
}