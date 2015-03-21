/****
	*@author    Shen
	*@title     poj 1064
	*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-5;

int n, k;
double l, v[10005];
double maxa = 0;

bool test(int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += int(v[i] / x);
    return sum >= k;
}

int Bsearch(int l, int r)
{
    int res = 0;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        //printf("l = %d, r = %d, mid = %d, res = %d.\n", l, r, mid, res);
        if (test(mid))
            res = max(res, mid), l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

void solve()
{
    maxa = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &l);
        l *= 100.0;
        v[i] = l;
        maxa = max(maxa, v[i]);
    }
    int ans = Bsearch(1, int(maxa));
    printf("%d.%02d\n", ans / 100, ans % 100);
}

int main()
{
    while (~scanf("%d%d", &n, &k))
        solve();
    return 0;
}