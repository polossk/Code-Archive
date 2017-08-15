/****
	*@PoloShen
	*Title:A
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize ("O2")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

int n;
vector<int> a;
void solve(){
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << endl;
}

int main(){
    cin >> n;
    solve();
    return 0;
}
