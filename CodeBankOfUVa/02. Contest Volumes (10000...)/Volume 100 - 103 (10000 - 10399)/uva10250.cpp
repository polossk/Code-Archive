///uva 10250
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
double sina, cosa, dx, dy, d;
double x, x_1, x_2, x3, x4;
double y, y_1, y_2, y3, y4;
void solve()
{
    x = (x_1 + x_2) * 0.5;
    y = (y_1 + y_2) * 0.5;
    dx = (x_2 - x_1);
    dy = (y_2 - y_1);
    d = sqrt(dx * dx + dy * dy);
    sina = dy / d;
    cosa = dx / d;
    x3 = x - sina * d * 0.5;
    y3 = y + cosa * d * 0.5;
    x4 = x + sina * d * 0.5;
    y4 = y - cosa * d * 0.5;
    printf("%.10lf %.10lf %.10lf %.10lf\n", x3, y3, x4, y4);
}
int main()
{
    while (scanf("%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2) != EOF)
        solve();
    return 0;
}
