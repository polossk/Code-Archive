//10110
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    unsigned int n, d;
    while (cin >> n && n)
    {
        d = sqrt(double(n));
        if (d * d == n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}