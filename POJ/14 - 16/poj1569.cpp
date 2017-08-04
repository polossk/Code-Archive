#include <iostream>
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
    Vect(Point& a, Point& b){ x = b.x - a.x; y = b.y - a.y; }
    double length(){ return sqrt(x * x + y * y); }
};

struct Maxinum
{
    int i, j, k; double square;
    Maxinum(){ i = j = k = 0; square = 0;}
};

double operator^(const Vect& a, const Vect& b)
{
    return a.x * b.y - a.y * b.x;
}

double operator*(const Vect& a, const Vect& b)
{
    return a.x * b.x + a.y * b.y;
}

double angle(Vect& a, Vect& b)
{
    return asin( (a ^ b) / (a.length () * b.length ()) );
}

int main(){
    int n; while (cin >> n && n)
	{
        Point data[15];
        Maxinum Max;
        for (int i = 0; i < n; i++)
            cin >> data[i].ch >> data[i].x >> data[i].y;
        int i = 0, j = 1, k = 2, ip = 0;
        for (i = 0; i < n; i++)
		{
            for (j = i + 1; j < n; j++)
			{
                if (i >= j) continue;
                for (k = j + 1; k < n; k++)
				{
                    Vect v1(data[i], data[j]), v2(data[i], data[k]);
                    bool flag = 0;
                    double s = fabs(v1 ^ v2);
                    for (ip = 0; ip < n; ip++)
					{
                        if (ip == i || ip == j || ip == k) continue;
                        flag = 1;
                        Vect v1(data[ip], data[i]);
                        Vect v2(data[ip], data[j]);
                        Vect v3(data[ip], data[k]);
						double s1 = fabs(v1 ^ v2);
						double s2 = fabs(v2 ^ v3);
						double s3 = fabs(v3 ^ v1);
                        double tmp = s1 + s2 + s3;
                        if (fcmp(tmp, s) == 0) { flag = 0; break; }
                        else continue;
                    }
                    if (flag)
					{
                        if (Max.square < s)
						{
                            Max.square = s;
                            Max.i = i;
                            Max.j = j;
                            Max.k = k;
                        }
                        continue;
                    }
                    else continue;
                }
            }
        }
        cout << data[Max.i].ch;
        cout << data[Max.j].ch;
        cout << data[Max.k].ch;
        cout << endl;
    }
    return 0;
}
