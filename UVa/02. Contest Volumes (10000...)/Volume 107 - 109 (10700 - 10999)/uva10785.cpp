/****
	*@PoloShen
	*Title:UVaOJ 10785
	*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const string kStr("AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR");

void solve(int case_num){
    int n; cin >> n;
    string ans(kStr.substr(0,n));
    string odd,even;
    for(int i = 0; i < n; i += 2) odd  += ans[i];
    for(int i = 1; i < n; i += 2) even += ans[i];
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    cout << "Case " << case_num << ": ";
    for(int i = 0; i < n; i++)
        if(i&1) cout << even[i>>1];
        else cout << odd[i>>1];
    cout << endl;
}

int main(){
    int T; cin >> T;
    int tt = 0;
    while (T--) solve(++tt);
    return 0;
}