#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double eps = 1e-8;
int sgn(double d) { return (d < -eps)? (-1): ((d > +eps)? (+1): (0)); }
int fcmp(double a, double b) { return sgn(a - b); }
struct Point
{
    double x, y;
    Point(){x=0;y=0;}
    Point(double _x, double _y){ x = _x; y = _y; }
};
bool operator==(const Point& a, const Point& b)
{
    return (fcmp(a.x, b.x) == 0) && (fcmp(a.y, b.y) == 0);
}
int main()
{
    double x[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (cin >> x[1] >> x[2])
	{
        cin >> x[3] >> x[4];
        cin >> x[5] >> x[6];
        cin >> x[7] >> x[8];
		Point p1(x[1], x[2]);
        Point p2(x[3], x[4]);
        Point p3(x[5], x[6]);
        Point p4(x[7], x[8]);
        Point pa, pb, pc;
        if (p1 == p3)
		{
			pa.x = x[1]; pa.y = x[2];
			pb.x = x[3]; pb.y = x[4];
			pc.x = x[7]; pc.y = x[8];
		}
        else if (p1 == p4)
		{
			pa.x = x[1]; pa.y = x[2];
			pb.x = x[3]; pb.y = x[4];
			pc.x = x[5]; pc.y = x[6];
		}
        else if (p2 == p3)
		{
			pa.x = x[3]; pa.y = x[4];
			pb.x = x[1]; pb.y = x[2];
			pc.x = x[7]; pc.y = x[8];
		}
        else if (p2 == p4)
		{
			pa.x = x[3]; pa.y = x[4];
			pb.x = x[1]; pb.y = x[2];
			pc.x = x[5]; pc.y = x[6];
		}
		double ansx = 0, ansy = 0;
		ansx = ((pb.x + pc.x) / 2 - pa.x) * 2.0 + pa.x;
		ansy = ((pb.y + pc.y) / 2 - pa.y) * 2.0 + pa.y;
		printf("%.3lf %.3lf\n", ansx, ansy);
	}
    return 0;
}
