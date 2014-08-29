#include <iostream>
#include <cstdio>
using namespace std;
int n1, n2, res, maxn;

int calc(int n)
{
    for (int i = 1; ; i++)
	{
        if (n == 1) return i;
        if (n % 2 == 1) n = 3 * n + 1;
        else n = n / 2;
    }
}

void solve()
{
	res = 0;
	int tmp = 0, nl, nr;
	nl = min(n1, n2);
	nr = max(n1, n2);
    for (int i = nl; i <= nr; i++)
	{
        tmp = calc(i);
        if (tmp > res) res = tmp;
    }
    cout << n1 << " " << n2 << " " << res << endl;
}

int main()
{
    while ( ~scanf("%d%d", &n1, &n2)) solve();
    return 0;
}
