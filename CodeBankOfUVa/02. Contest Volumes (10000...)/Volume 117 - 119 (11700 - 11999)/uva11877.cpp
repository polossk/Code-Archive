/****
	*@PoloShen
	*Title:A
	*/
#include <iostream>
using namespace std;
void solve(int n){
    int sum = 0, hg = 0;
    int now = n;
    while (now >1){
        hg = now / 3;
        sum += hg;
        now = now % 3;
        now = now + hg;
        if (now == 2){
            sum++;
            now = 0;
            hg = 0;
        }
    }
    cout << sum << endl;
}
int main(){
	int n;
	while (cin >> n && n){
        solve(n);
	}
    return 0;
}