#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Point
{
    double x, y;
    Point(){};
    Point(double _x, double _y){ x = _x; y = _y; }
}po[100];

inline double operator^(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}

inline double getarea(Point pg[], int n){
    double area=0;
    pg[n] = pg[0];
    for (int i = 0; i < n; i++)
        area += (pg[i] ^ pg[i + 1]);
    return fabs(area) / 2.0;
}
int main()
{
    int T;
    for (scanf("%d", &T); T; T--)
	{
        int n, m, ans = 0, num;
        double area = 0.0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lf%lf", &po[i].x, &po[i].y);
        Point pg[100];
        scanf("%d", &m);
        for (int i = 1, k, tp; i <= m; i++)
		{
            scanf("%d", &num);
            k=0;
            for(int j = 0; j < num; j++)
			{
                scanf("%d", &tp);
                pg[k++] = po[tp];
            }
            double ar = getarea(pg, num);
            if (ar > area){ area=ar; ans=i; }
        }
        printf("%d\n", ans);
    }
    return 0;
}