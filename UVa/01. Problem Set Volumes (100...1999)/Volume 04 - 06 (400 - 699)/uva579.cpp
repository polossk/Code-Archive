///uva 579
#include <cstdio>
using namespace std;
int main()
{
    int h, m;
    double arg;
    while(scanf("%d:%d", &h, &m))
    {
        if (h == 0 && m == 0)
            break;
        if (h == 12)
            h = 0;
        arg = (h * 30.0 + m * 1.0 / 2) - m * 6.0;
        if (arg < 0)
            arg = -arg;
        if (arg > 180)
            arg = 360 - arg;
        printf("%.3lf\n", arg);
    }
    return 0;
}
