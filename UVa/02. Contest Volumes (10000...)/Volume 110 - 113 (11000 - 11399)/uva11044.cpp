#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << (n / 3) * (m / 3) << endl;
    }
    return 0;
}
