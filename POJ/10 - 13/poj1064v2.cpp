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

bool test(double x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += int(v[i] / x);
    return sum >= k;
}

double Bsearch(double l, double r)
{
    while (r - l > eps)
    {
        double mid = (r + l) * 0.5;
        if (test(mid))
            l = mid;
        else r = mid;
    }
    return r;
}

void solve()
{
    maxa = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &l);
        v[i] = l;
        maxa = max(maxa, v[i]);
    }
    double ans = Bsearch(0.0, maxa);
    ans = 0.01 * int(ans * 100);
    //G++
        printf("%.2f\n", ans);
    //C++
    //  printf("%.2lf\n", ans);
}

int main()
{
    while (~scanf("%d%d", &n, &k))
        solve();
    return 0;
}