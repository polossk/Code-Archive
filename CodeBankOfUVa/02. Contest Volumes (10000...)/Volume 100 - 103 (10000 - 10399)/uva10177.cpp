#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int64;
int main()
{
    int64 n;
    while (cin >> n)
    {
        int64 s1 = n * (n + 1) /2;
        int64 s2 = 0, s3 = 0, s4 = 0;
        int64 r2 = 0, r3 = 0, r4 = 0;
        for (int i = 1; i <= n; i++)
        {
            s2 += i * i;
            s3 += i * i * i;
            s4 += i * i * i * i;
        }
        r2 = s1 * s1 - s2;
        r3 = s1 * s1 * s1 - s3;
        r4 = s1 * s1 * s1 * s1 - s4;
        cout << s2 << " " << r2 << " ";
        cout << s3 << " " << r3 << " ";
        cout << s4 << " " << r4 << endl;
    }
    return 0;
}
