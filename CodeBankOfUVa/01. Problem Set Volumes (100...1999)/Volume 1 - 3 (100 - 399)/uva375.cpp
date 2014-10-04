///uva 375
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = 2 * asin(1.0);
double B, H, r, h, R;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf", &B, &H);
        R = (H * H + B * B * 0.25);
        R = sqrt(R);
        R = B * H / (2.0 * R + B);
        h = H;
        r = R;
        while (r >= 0.000001)
        {
            h = h - 2.0 * r;
            r = R * h / H;
        }
        printf("%13lf\n", (H - h) * pi);
        if (t) printf("\n");
    }
}
