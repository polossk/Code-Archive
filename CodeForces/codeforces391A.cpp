/****
	*@PoloShen
	*Title:A
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

string source;

void solve(){
    int sz = source.size();
    int ans = 0;
    for (int i = 0; i < sz; i++){
        int sum=1;
        if (source[i] == source[i-1]){
            while (source[i] == source[i-1]){
                i++;
                sum++;
            }
        }
        ans += (1 - sum % 2);
    }
    cout << ans << endl;
}

int main(){
	while (getline(cin, source)) solve();
    return 0;
}