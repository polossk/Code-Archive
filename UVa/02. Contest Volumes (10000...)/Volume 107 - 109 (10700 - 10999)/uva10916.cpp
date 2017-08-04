#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double lg2 = log(2.0);
int main()
{
    int n;
    while (cin >> n && n)
    {
        int x = (n - 1960) / 10;
        double tmp = pow(2, x + 2) * lg2;
        double sum = 0;
        int i = 1;
        while (sum <= tmp)
            sum += log(i++);
        cout << i - 2 << endl;
    }
    return 0;
}
