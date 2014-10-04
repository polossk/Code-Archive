/****
	*@PoloShen
	*Title:B
	*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> command;
    int pos = 0;
    string inp; int i = 0;
    while (n--){
        cin >> inp;
        if (inp[0] == 'L'){
            command.push_back(-1);
            pos += -1;
        }
        else if (inp[0] == 'R'){
            command.push_back(1);
            pos += 1;
        }
        else if (inp[0] == 'S'){
            cin >> inp;
            int tmp;
            cin >> tmp;
            pos += command[tmp-1];
            command.push_back(command[tmp-1]);
        }
    }
    cout << pos << endl;
}
int main(){
	int T; cin >> T;
	while (T--) solve();
    return 0;
}