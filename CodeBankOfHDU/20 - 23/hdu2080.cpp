#include <math.h>
#include <stdio.h>

int main(void)
{
    int n;
    double x[2], y[2], t;
    
    scanf("%d", &n);
    while (n-- && scanf("%lf%lf%lf%lf", x, y, x+1, y+1))
        printf("%.2f\n", (t=asin(fabs(x[0]*y[1]-x[1]*y[0])/sqrt(x[0]*x[0]+y[0]*y[0])/sqrt(x[1]*x[1]+y[1]*y[1]))/acos(-1.0)*180)?x[0]*x[1]<=0&&y[0]*y[1]<=0?180-t:t:x[0]*x[1]<0?180:0);

    return 0;
}
