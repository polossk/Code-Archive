/****
	*@PoloShen
	*Title:Uva 591
	*/
#include <algorithm>
#include <iostream>
using namespace std;

void solve(int n){
    int a[105], sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int avg = sum / n;
    int dif = 0;
    for (int i = 0; i < n; i++) dif += ((a[i] - avg) > 0)? (a[i] - avg): 0;
    cout << "The minimum number of moves is " << dif << '.' << endl;
    return;
}

int main(){
	int tt = 0, n = 0;
	while (cin >> n && n){
        cout << "Set #" << ++tt << endl;
        solve(n);
        cout << endl;
	}
    return 0;
}