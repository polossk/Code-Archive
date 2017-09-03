/****
	*@author    Shen
	*@title     A
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize ("O2")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

typedef long long int64;

int n, m;
int a[205];

void solve()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    if (sum == 0)
        printf("0.00\n");
    else if (n == m)
        printf("inf\n");
    else
    {
        double tmp = sum * 1.0 / (n - m);
        printf("%.2lf\n", tmp);
    }
}

int main()
{
    while (cin >> n) solve();
    return 0;
}
