#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
        cout << n * (m - 1) + n - 1 << endl;
    return 0;
}
