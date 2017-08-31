#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s; cin >> s;
    if (s.size() == 5) cout << 3 << endl;
    else if (  s[0] == 'o' && s[1] == 'n'
            || s[0] == 'o' && s[2] == 'e'
            || s[1] == 'n' && s[2] == 'e')
                cout << 1 << endl;
    else cout << 2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}