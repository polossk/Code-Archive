/****
	*@PoloShen
	*Title:UVa 621
	*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void solve(){
    string str;
    cin >> str;
    if (str == "1" || str == "4" || str == "78")
        cout << '+' << endl;
    else{
        int sz = str.size();
        if (str[sz-2] == '3' && str[sz-1] == '5')
            cout << '-' << endl;
        else if (str[0] == '9' && str[sz-1] == '4')
            cout << '*' << endl;
        else if (str[0] == '1' && str[1] == '9' && str[2] == '0')
            cout << '?' << endl;
        else return;
    }
    return;
}

int main(){
    int n; cin >> n;
    while (n--) solve();
    return 0;
}