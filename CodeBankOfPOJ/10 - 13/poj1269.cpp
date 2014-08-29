#include <iostream>
#include <cstdio>
using namespace std;

struct Point{ int x, y; };

struct Line{ int a, b, c; };

inline int line(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}

Line lineform(int x1, int y1, int x2, int y2)
{
    Line temp;
    temp.a = y2 - y1;
    temp.b = x1 - x2;
    temp.c = x2 * y1 - x1 * y2;
    return temp;
}

void LineIntersect(Line l1, Line l2, double& x, double& y)
{
    double d = l1.a * l2.b - l2.a * l1.b;
    x = (l2.c * l1.b - l1.c * l2.b)/d;
    y = (l2.a * l1.c - l1.a * l2.c)/d;
}

int n;
Point p1, p2, p3, p4;
	
int main()
{
    scanf("%d", &n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--)
	{
        scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
        scanf("%d%d%d%d", &p3.x, &p3.y, &p4.x, &p4.y);
		if (line(p2.x - p1.x, p2.y - p1.y, p3.x - p1.x, p3.y - p1.y) == 0
         && line(p2.x - p1.x, p2.y - p1.y, p4.x - p1.x, p4.y - p1.y) == 0)
            printf("LINE\n");
        else if (line(p2.x - p1.x, p2.y - p1.y, p4.x - p3.x, p4.y - p3.y) == 0)
            printf("NONE\n");
        else{
            Line l1 = lineform(p1.x, p1.y, p2.x, p2.y);
            Line l2 = lineform(p3.x, p3.y, p4.x, p4.y);
			double x = 0, y = 0;
            LineIntersect(l1, l2, x, y);
            printf("POINT %.2lf %.2lf\n", x, y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}