/****
	*@PoloShen
	*Title:B
	*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long int64;
int n;
int64 bi[55];
int64 a, b;
void solve(){
	a = bi[n] - 1;
    b = 0;
	char str[55];
	cin >> str;
	for (int i = 0; i < n; i++){
        if (str[i] == 'R') b += bi[i];
	}
	cout << a - b << endl;
}

int main(){
    bi[0] = 1;
    for (int i = 1; i < 55; i++){
        bi[i] = bi[i - 1] * 2;
    }
    while (cin >> n) solve();
    return 0;
}