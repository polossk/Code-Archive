#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, x[3], y[3];
    double s;

    scanf("%d", &n);
    while (n-- && scanf("%d%d%d%d", x, y, x+1, y+1))
    {
        if ((x[2] = x[0]+y[0]) > (y[2] = x[1]+y[1]))
        {
            swap(x[0], x[1]);
            swap(y[0], y[1]);
            swap(x[2], y[2]);
        }
        if (x[2] == y[2])
        {
            printf("%.3f\n", sqrt(pow(x[0]-x[1], 2)+pow(y[0]-y[1], 2)));
        }
        else
        {
            s = sqrt((double)2.0)*(x[2] + x[1] - x[0] + y[2]*(y[2]-1)/2.0 - x[2]*(x[2]+1)/2.0);
            for (; x[2] < y[2]; x[2]++)
                s += sqrt((double)2*x[2]*x[2]+2*x[2]+1);
            printf("%.3f\n", s);
        }
    }

    return 0;
}
