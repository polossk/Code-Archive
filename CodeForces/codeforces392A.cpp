/****
	*@PoloShen
	*Title:C
	*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        int x = n * sqrt(double(2));
        if (n == 0) cout << 1 << endl;
        else cout << x * 4 << endl;
    }
    return 0;
}