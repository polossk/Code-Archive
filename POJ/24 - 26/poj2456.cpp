/****
	*@author    Shen
	*@title     poj 2456
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize ("O2")

#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100005;
int data[MaxN];
int n, c;

bool test(int val)
{
    int cnt = 1, cur = data[0];
    for (int i = 0; i < n; i++)
    {
        while (i < n && data[i] - cur < val)
            i++;
        cur = data[i];
        if (i < n && ++cnt == c)
            return true;
    }
    return false;
}

int Bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (test(mid))
            l = mid + 1;
        else
            r = mid;
    }
    return l - 1;
}

void solve()
{
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    sort(data, data + n);
    printf("%d\n", Bsearch(0, data[n - 1] - data[0] + 1));
}

int main()
{
    while (scanf("%d%d", &n, &c) != EOF)
        solve();
    return 0;
}
