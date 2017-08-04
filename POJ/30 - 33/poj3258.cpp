/****
	*@author    Shen
	*@title     poj 3258
	*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
int l, v[50005];
int maxa = 0;

bool test(int x)
{
    int sum = 0, st = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (v[i] - v[st] <= x)
            sum++;
        else
            st = i;
    }
    return sum <= k;
}

int Bsearch(int l, int r)
{
    int res = r;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (test(mid))
             l = mid + 1;
        else
            res = min(res, mid), r = mid - 1;
    }
    return res;
}

void solve()
{
    maxa = l;
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &l);
        v[i] = l;
    }
    v[n + 1] = maxa;
    sort(v, v + n + 2);
    int ans = Bsearch(0, maxa);
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d%d%d",&l, &n, &k))
        solve();
    return 0;
}