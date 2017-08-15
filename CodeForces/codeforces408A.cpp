/****
	*@author    Shen
	*@title     a
	*/

#include <iostream>
using namespace std;

typedef long long int64;

inline int calc(int t)
{
    return 15 + 5 * t;
}

int n;
int64 casher[105];
int number[105];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    for (int i = 0; i < n; i++)
    {
        casher[i] = 0;
        for (int j = 0; j < number[i]; j++)
        {
            int k; cin >> k;
            casher[i] += calc(k);
        }
    }
    int ans = casher[0];
    for (int i = 0; i < n; i++)
    {
        if (casher[i] < ans) ans = casher[i];
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}
