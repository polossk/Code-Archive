/****
	*@PoloShen
	*Title:uva 846
	*/
#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int st, ed;
    cin >> st >> ed;
    int dif = ed - st;
    int n = (int)sqrt(double(dif));
    if (dif == 0)
            cout << 0 << endl;
    else if (dif <= n * n)
            cout << 2 * n - 1 << endl;
    else if (n * n + 1 <= dif && dif <= n * n + n)
            cout << 2 * n << endl;
    else if (n * n + n + 1 <= dif && dif <= n * n + 2 * n + 1)
            cout << 2 * n + 1 << endl;
    return;
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
