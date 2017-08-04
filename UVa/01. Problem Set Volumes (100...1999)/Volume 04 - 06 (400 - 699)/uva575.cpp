//575
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    long long bin[33], dec[33];
    bin[0] = 1;
    dec[0] = 0;
    for (int i = 1; i < 33; i++)
    {
        bin[i] = 2 * bin[i - 1];
        dec[i] = bin[i] - 1;
    }
    while (getline(cin, s) && s != "0")
    {
        int sz = s.size();
        long long ans = 0;
        for (int i = 0; i < sz; i++)
            ans += (s[i] - '0') * dec[sz - i];
        cout << ans << endl;
    }
    return 0;
}
