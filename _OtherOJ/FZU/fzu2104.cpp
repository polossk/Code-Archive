/****
    *@PoloShen
    *Title:C
    */
#include <iostream>
#include <cmath>
using namespace std;

inline int Floor(int n, int x){ return floor((double)(n / x)); }
int solve(int n, int L, int R){
    int ans = 0;
    for (int i = L; i <= R; ++i){
        ans += (Floor(n, i));
    }
    return ans;
}
int main(){
    int t, n, l, r;
    cin >> t;
    while (t--){
        cin >> n >> l >> r;
        cout << solve(n, l, r) << endl;
    }
    return 0;
}