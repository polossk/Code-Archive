#include <iostream>
#include <cmath>
using namespace std;

const int maxi = 1000000;
int main()
{
    long long  a, i, j, t, flag;
    while (cin >> a && a != -1)
    {
        for (i = 2; i <= maxi; i++)
        {
            while (!(a % i))
            {
                cout << "    " << i << endl;
                a /= i;
            }
            if(a == 1)
                break;
        }
        if (i > maxi)
            cout << "    " << a << endl;
        cout << endl;
    }
    return 0;
}
