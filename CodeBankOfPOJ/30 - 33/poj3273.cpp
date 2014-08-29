/****
	*@author    Shen
	*@title     poj 3273
	*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
int r, v[100005];
int maxa = 0, mina = 0;

bool test(int x)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum + v[i] <= x)
            sum += v[i];
        else
            cnt++, sum = v[i];
    }
    //printf("\t%s with x = %d, result is that sum = %d.\n", __func__, x, sum);
    return cnt <= k;
}

int Bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = (r + l) / 2;
        //printf("l = %d, r = %d, mid = %d.\n", l, r, mid);
        if (test(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solve()
{
    maxa = mina = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        maxa += v[i];
        mina = max(mina, v[i]);
    }
    int ans = Bsearch(mina, maxa);
    printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d%d", &n, &k))
        solve();
    return 0;
}