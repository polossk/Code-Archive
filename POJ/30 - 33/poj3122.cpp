/****
	*@author    Shen
	*@title     poj 3122
	*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-5;

int n, f;
double r, v[10005];
double maxa = 0;

bool test(double x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += int(v[i] / x);
    return sum >= (f + 1);
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
    return l;
}

void solve()
{
    scanf("%d%d", &n, &f);
    maxa = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &r);
        v[i] = r * r * PI;
        maxa = max(maxa, v[i]);
    }
    double ans = Bsearch(0.0, maxa);
    /* G++ *///printf("%.4f\n", ans);
	/* C++ */printf("%.4lf\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}