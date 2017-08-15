/****
	*@PoloShen
	*Title:Codeforces Round #225 (Div. 1) A
	*Also Named:Codeforces 383A
	*/
#include <iostream>
using namespace std;
int main(){
    int64_t n, suc = 0, ans = 0, tmp;
    cin >> n;
    while (n--){
        cin >> tmp;
        if (tmp) suc++;
        else ans += suc;
    }
    cout << ans << endl;
    return 0;
}