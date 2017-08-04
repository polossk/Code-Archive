///uva 10387
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = 2 * acos(0);
double a, b, s, m, n, A, v;

void solve()
{
    double aa = a * m, bb = b * n;
    A = atan(bb / aa) * 180 / pi;
    v = sqrt(bb * bb + aa * aa) / s;
    printf("%.2lf %.2lf\n", A, v);
}

int main()
{
    while(scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n)
          && (a || b || s || m || n))
        solve();
    return 0;
}
