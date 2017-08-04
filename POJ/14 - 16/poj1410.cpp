#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define Pi 3.141592653568979323846
#define eps 1e-8
#define sgn(d) (( (d) < -eps)? (-1): ( ( (d) > +eps)? (+1): (0)))
#define Sqr(x) ((x)* (x))
#define fabs(x) ((x) < 0? ( -(x)): (x))
#define Deg2Red(deg) ((deg) * Pi / 180.0)
#define Red2Deg(red) ((red) * 180.0 / Pi)
#define Sin(deg) (sin(Deg2Red((deg))))
#define Cos(deg) (cos(Deg2Red((deg))))
#define ArcSin(val) (Red2Deg(asin((val))))
#define ArcCos(val) (Red2Deg(acos((val))))
#define fcmp(a, b) (sgn ((a) - (b)))
#define VEC(l) (l.b - l.a)

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

Vect operator-(const Point& a, const Point& b)
{
    return Vect(a.x - b.x, a.y - b.y);
}

double operator^(const Vect& a, const Vect& b)
{
    return a.x * b.y - a.y * b.x;
}

double operator*(const Vect& a, const Vect& b)
{
    return a.x * b.x + a.y * b.y;
}

//线段类
struct Segment
{
    Point a, b;
    Segment(){};
    Segment(Point _a,Point _b){ a = _a; b = _b; }
};

bool operator==(const Point& a, const Point& b)
{
    return (fcmp(a.x, b.x) == 0) && (fcmp(a.y, b.y) == 0);
}

//向量 OA^OB,AB^AP
double Xmupl(const Point& O, const Point& A, const Point& B)
{
    return (A - O) ^ (B - O);
}
double operator^(const Segment& l, const Point& p)
{
    return VEC(l) ^ (p - l.a);
}

inline bool Point_Seg_on(const Segment& l, const Point& p)
{
    return sgn(l ^ p) == 0
        && sgn((l.b - l.a) * p) >= 0
        && sgn((l.a - l.b) * p) >= 0;
}

bool FASTintersect(double a, double b, double c, double d)
{
    bool flag = 0;
    flag = flag || fcmp(max(a, b), min(c, d)) < 0;
    flag = flag || fcmp(max(c, d), min(a, b)) < 0;
    return !flag;
}

//判断两条线段相交，包含端点重合
bool Seg_Seg_intersect(const Segment& l1, const Segment& l2)
{
    bool flag = 0;
    //快速排斥试验
    flag = FASTintersect(l1.a.x, l1.b.x, l2.a.x, l2.b.x);
    flag = flag && FASTintersect(l1.a.y, l1.b.y, l2.a.y, l2.b.y);
    if (!flag) return flag;
    else
    {
        flag = (sgn(l1 ^ l2.a) * sgn(l1 ^ l2.a)) <= 0;
        flag = flag || ((sgn(l2 ^ l1.a) * sgn(l2 ^ l1.b)) <= 0);
        return flag;
    }
}

//矩形类
struct Rectangle
{
    Point pld, prd, plu, pru;
    Point pfocus;
    Rectangle(){};
    Rectangle(Point st, Point ed)
    {
        int lx, rx, uy, dy;
        if (st.x < ed.x) { lx = st.x; rx = ed.x; }
        else { rx = st.x; lx = ed.x; }
        if (st.y < ed.y) { dy = st.y; uy = ed.y; }
        else { dy = ed.y; uy = st.y; }
        pld.x = lx; pld.y = dy;
        prd.x = rx; prd.y = dy;
        plu.x = lx; plu.y = uy;
        pru.x = rx; pru.y = uy;
        pfocus.x = (lx + rx) / 2;
        pfocus.y = (uy + dy) / 2;
    }
    inline int Square()
    {
        return (pru.x - pld.x) * (pru.y - pld.y);
    }
};

//三角型面积
double square(const Point& O, const Point& A, const Point& B)
{
    return 0.5 * fabs(Xmupl(O, A, B));
}

void Rectangle_to_Segment(const Rectangle& source,
                          Segment& u, Segment& d,
                          Segment& l, Segment& r)
{
    u.a = source.plu; u.b = source.pru;
    d.a = source.pld; d.b = source.prd;
    l.a = source.pld; l.b = source.plu;
    r.a = source.prd; r.b = source.pru;
}
int main()
{
    int n; cin >> n;
    while (n--)
    {
        Point st, ed, st1, ed1;
        cin >> st.x >> st.y >> ed.x >> ed.y;
        cin >> st1.x >> st1.y >> ed1.x >> ed1.y;
        Rectangle Rec(st1, ed1);
        Segment seg0(st, ed);
        double square_st[4], square_ed[4];
        square_st[0] = square(st, Rec.pld, Rec.prd);
        square_st[1] = square(st, Rec.prd, Rec.pru);
        square_st[2] = square(st, Rec.pru, Rec.plu);
        square_st[3] = square(st, Rec.plu, Rec.pld);
        square_ed[0] = square(ed, Rec.pld, Rec.prd);
        square_ed[1] = square(ed, Rec.prd, Rec.pru);
        square_ed[2] = square(ed, Rec.pru, Rec.plu);
        square_ed[3] = square(ed, Rec.plu, Rec.pld);
        double sst = 0, sed = 0;
        bool flag = 1;
        for (int i = 0; i < 4; i++)
        {
            sst += square_st[i];
            sed += square_ed[i];
        }
        if (!flag) continue;
        else
        {
            if (sst == Rec.Square() && sed == Rec.Square())
            {
                puts("T");
                continue;
            }
            else
            {
                bool b[4] = {0, 0, 0, 0};
                Segment seg[4];
                Rectangle_to_Segment(Rec, seg[0], seg[1], seg[2], seg[3]);
                flag = 0;
                for (int i = 0; i < 4; i++)
                {
                    b[i] = Seg_Seg_intersect(seg[i], seg0);
                    if (b[i] == 1) { puts("T"); flag = 1; break; }
                }
                if (flag) continue;
                else { puts("F"); continue; }
            }
        }
    }
    return 0;
}
