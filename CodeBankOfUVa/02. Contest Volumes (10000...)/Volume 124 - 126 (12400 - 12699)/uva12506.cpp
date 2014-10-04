/****
	*@PoloShen
	*Title:C
	*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> namelist;
    string name;
    for (int i = 0; i < n; i++){
        cin >> name;
        namelist.push_back(name);
    }
    sort(namelist.begin(), namelist.end());
    int pos = 0,ans = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < namelist[i].size(); j++){
				if (namelist[i].at(j) != namelist[i+1].at(j)){
					ans += max(pos,j + 1);
					pos = j + 1;
					break;
				}
			}
		}
    printf("%d\n",ans+pos);
}

int main(){
    int t; cin >> t;
    while (t--) solve();
    return 0;
}