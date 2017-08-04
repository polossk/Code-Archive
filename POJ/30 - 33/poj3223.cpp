#include <iostream>
#include <cmath>
#include <algorithm>
//#include <fstream>
//#include <string>
#include <cstdio>
//#include <cstdlib>
using namespace std;

#define Pi 3.141592653568979323846
#define eps 1e-8
#define infin 1e20
#define coef1 (0.618)
#define coef2 (1-0.618)

#define Sqr(x) ((x)*(x))
#define Sqrt(x) (sqrt((x)))
#define Abs(x) ((x)<0?(-(x)):(x))

#define Max(a, b) ((a)>(b)?(a):(b))
#define Min(a, b) ((a)<(b)?(a):(b))
#define sgn(d) (((d)<-eps)?(-1):(((d)>+eps)?(+1):(0)))
#define fcmp(a, b) (sgn((a)-(b)))


#define Deg2Red(deg) ((deg)*Pi/180.0)
#define Red2Deg(red) ((red)*180.0/Pi)
#define Sin(deg) (sin(Deg2Red((deg))))
#define Cos(deg) (cos(Deg2Red((deg))))
#define ArcSin(val) (Red2Deg(asin((val))))
#define ArcCos(val) (Red2Deg(acos((val))))

#define VEC(l) (l.b-l.a)
#define readPoint(p) (cin>>ch>>(p).x>>ch>>(p).y>>ch)
#define PrintAngle(b) (printf("%.3lf\n",b))
char ch;

struct Point
{
    double x, y; char ch;
    Point(){ x = y = 0; ch = '\0'; }
    Point(double _x, double _y){ x = _x; y = _y; ch = '\0'; }
};

struct Vect
{
    double x, y;
    Vect(){ x = y = 0; }
    Vect(double _x, double _y){ x = _x; y = _y; }
	Vect(const Point p){ x = p.x; y = p.y; }
    Vect(Point& a, Point& b){ x = b.x - a.x; y = b.y - a.y; }
    double length(){ return sqrt(x * x + y * y); }
};

inline Vect operator*(const double k, const Vect& v)
{
    return Vect(k * v.x, k * v.y);
}

inline double operator^(const Vect& a, const Vect& b)
{
    return a.x * b.y - a.y * b.x;
}

inline double operator*(const Vect& a, const Vect& b)
{
    return a.x * b.x + a.y * b.y;
}

//两点差构造向量，点加向量
inline Vect operator-(const Point& a, const Point& b){
    return Vect(a.x - b.x, a.y - b.y);
}

inline Point operator+(const Point& p, const Vect& v){
    return Point(p.x + v.x, p.y + v.y);
}

//线段类
struct Segment
{
    Point a, b;
    Segment(){};
    Segment(Point _a,Point _b){ a = _a; b = _b; }
};

//向量 OA^OB,AB^AP
inline double Xmupl(const Point& O, const Point& A, const Point& B)
{
    return (A - O) ^ (B - O);
}

inline double operator*(const Segment& l, const Point& p)
{
    return VEC(l) * (p - l.a);
}

inline double operator^(const Segment& l, const Point& p)
{
    return VEC(l) ^ (p - l.a);
}

double cosAngle(const Point& O, const Point& A, const Point& B)
{
    Vect v1 = (A - O), v2 = (B - O);
    return (v1 * v2) / v1.length() / v2.length();
}

//直线类
struct Line
{
    double a, b, c;
    Line(){};
    Line(double _a, double _b, double _c){ a = _a; b = _b; c = _c; }
    Line(Segment _l)
    {
        a = _l.b.y - _l.a.y;
        b = _l.a.x - _l.b.x;
        c = _l.b.x * _l.a.y - _l.a.x * _l.b.y;
    }
    Line(Point _a, Point _b)
    {
        a = _b.y - _a.y;
        b = _a.x - _b.x;
        c = _b.x * _a.y - _a.x * _b.y;
    }
};

void Coef_of_line(const Line& l, double& a, double& b, double& c)
{
    a = l.a; b = l.b; c = l.c;
}

inline double Point_Line_distence(const Point p, const Line l)
{
    return Abs(l.a * p.x + l.b * p.y + l.c) / Sqrt(Sqr(l.a) + Sqr(l.b));
}

//判断等值
bool operator==(const Point& a, const Point& b)
{
    return (fcmp(a.x, b.x) == 0) && (fcmp(a.y, b.y) == 0);
}

bool operator==(const Segment& a, const Segment& b)
{
    return ((a.a == b.a) && (a.b == b.b));
}

bool operator==(const Line& a, const Line& b)
{
    return (fcmp(a.a * b.b, a.b * b.a)
            && fcmp(a.a * b.c, a.c * b.a)
            && fcmp(a.b * b.c, b.b * a.c));
}

//判断直线重合
bool Line_Line_coincide(const Line& l1, const Line& l2)
{
    return (l1 == l2);
}

//判断直线平行，不包含两直线重合
bool Line_Line_parallel_only(const Line& l1, const Line& l2)
{
    return (l1.a * l2.b == l2.a * l1.b) && (!(l1 == l2));
}

//判断直线平行，包含两直线重合
bool Line_Line_parallel_ex(const Line& l1, const Line& l2)
{
    return (l1.a * l2.b == l2.a * l1.b);
}

//判断线段平行，包含所在直线相同
bool Seg_Seg_parallel_ex(const Segment& a, const Segment& b)
{
    Line l1(a), l2(b);
    return Line_Line_parallel_ex(l1, l2);
}

//判断两条直线是否相交
bool Line_Line_intersect(const Line& l1, const Line& l2)
{
    return !Line_Line_parallel_ex(l1, l2);
}

//两直线交点
Point Line_Line_intersection(const Line& l1, const Line& l2)
{
    Point p;
    p.x = -(l2.b * l1.c - l1.b * l2.c) / (l1.a * l2.b - l2.a * l1.b);
    p.y =  (l2.a * l1.c - l1.a * l2.c) / (l1.a * l2.b - l2.a * l1.b);
    return p;
}

ostream& operator<<(ostream& os, Point& p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

ostream& operator<<(ostream& os, Vect& v)
{
    os << "vector->" << "(" << v.x << "," << v.y << ")";
    return os;
}

ostream& operator<<(ostream& os, Segment& Seg)
{
    os << Seg.a << "->" << Seg.b;
    return os;
}

Point A, B, U, V;

void solve()
{
    scanf(" (%lf,%lf)", &B.x, &B.y);
    scanf(" (%lf,%lf)", &U.x, &U.y);
    scanf(" (%lf,%lf)", &V.x, &V.y);
    int d1 = Xmupl(U, A, B);
    int d2 = Xmupl(V, A, B);
    double b1 = sgn(d1), b2 = sgn(d2);
    Point Ud, Vd;
    if (b1 == -1 && b2 == -1) { Ud = U; Vd = V; }
    else if (b1 != -1 && b2 == -1)
    {
        Vd = V; Line l1(A, B), l2(U, V);
        Ud = Line_Line_intersection(l1, l2);
    }
    else if (b1 == -1 && b2 != -1)
    {
        Ud = U; Line l1(A, B), l2(U, V);
        Vd = Line_Line_intersection(l1, l2);
    }
    else { puts("0"); return; }
    Point ans; double res;
    while (true)
    {
        Point P1 = Ud + (coef2) * (Vd - Ud);
        Point P2 = Ud + (coef1) * (Vd - Ud);
        double c1 = cosAngle(P1, A, B);
        double c2 = cosAngle(P2, A, B);
        int flag = fcmp(c1, c2);
        if (flag == 1) { Ud = P1; continue; }
        else if (flag == -1) { Vd = P2; continue; }
        else if (flag == 0) { ans = P1; res = c1; break; }
    }
    res = ArcCos(res);
    PrintAngle(res);
}

int main()
{
    while (readPoint(A)) solve();
    return 0;
}
