/****
	*@author    Shen
	*@title     A
	*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int n;

void solve()
{
    string hamsters;
    int nstd = 0, nsit = 0;
    cin >> hamsters;
    for (int i = 0; i < n; i++)
        if (hamsters[i] == 'X')
            nstd++;
        else nsit++;
    if (nstd > nsit)
    {
        int ans = nstd - n / 2;
        for (int i = 0; nstd != nsit; i++)
        {
            if (hamsters[i] == 'X')
            {
                hamsters[i] = 'x';
                nstd--; nsit++;
            }
        }
        printf("%d\n%s\n", ans, hamsters.c_str());
    }
    else
    {
        int ans = nsit - n / 2;
        for (int i = 0; nstd != nsit; i++)
        {
            if (hamsters[i] == 'x')
            {
                hamsters[i] = 'X';
                nstd++; nsit--;
            }
        }
        printf("%d\n%s\n", ans, hamsters.c_str());
    }
}

int main()
{
    while (~scanf("%d", &n))
        solve();
    return 0;
}
