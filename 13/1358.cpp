// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1358                                             *
*****************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

struct point
{
	double x, y, d;
} C;

const double eps = 1e-8;
const double pi = acos(-1.0);

double R;

int dblcmp( double x )
{
	if( fabs(x) < eps )
		return 0;
	return x > 0 ? 1 : -1;
}

double dis( point& a, point& b )
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx+dy*dy);
}

double sqr( double x )
{
	return x*x;
}

double cross( point& k, point& a, point& b )
{
	point u, v;
	u.x = a.x - k.x;	u.y = a.y - k.y;
	v.x = b.x - k.x;	v.y = b.y - k.y;
	return u.x*v.y - v.x*u.y;
}

//线段和圆相交
//注意k= =
int seg_cri( point& c, point& a, point& b, point& res1, point& res2 )
{
	int k = -1;
	double aa = sqr(a.x-b.x) + sqr(a.y-b.y);
	double bb = 2*( (b.x-a.x)*(a.x-c.x) + (b.y-a.y)*(a.y-c.y) );
	double cc = sqr(c.x)+sqr(c.y)+sqr(a.x)+sqr(a.y)-R*R - 2*(c.x*a.x+c.y*a.y);

	//两交点, u1为靠近a的
	if( dblcmp(bb*bb-4*aa*cc) >= 0 )
	{
		double u1 = (-bb+sqrt(bb*bb-4*aa*cc))/2./aa;
		double u2 = (-bb-sqrt(bb*bb-4*aa*cc))/2./aa;
		if( u1 > u2 && dblcmp(u2) >= 0 )	swap(u1, u2);
		if( dblcmp(u1) >= 0 && dblcmp(u1-1) <= 0 )
		{
			res1.x = a.x + u1*(b.x-a.x);
			res1.y = a.y + u1*(b.y-a.y);
			++k;
		}
		if( dblcmp(u1-u2) && dblcmp(u2) >= 0 && dblcmp(u2-1) <= 0 )
		{
			res2.x = a.x + u2*(b.x-a.x);
			res2.y = a.y + u2*(b.y-a.y);
			++k;
		}
	}

	return k;
}

point change(point a)
{
	point res;
	res.x = R*a.x/a.d;
	res.y = R*a.y/a.d;
	return res;
}

double calang(point a, point b)
{
	double t;
	t = atan2(a.y, a.x) - atan2(b.y, b.x);
	while( dblcmp(t-pi) > 0 )
		t -= pi*2;
	while( dblcmp(t+pi) < 0 )
		t += pi*2;
	return t;
}

double calc( int n, point* p, point C )
{
	int i;
	double ans, ang;
	point temp1, temp2;

	p[n] = p[0];
	ans = ang = 0;
	for( i = 1; i <= n; ++i )
	{
		if( dblcmp(p[i-1].d-R) < 0 )
		{
			if( dblcmp(p[i].d-R) < 0 )
					ans += cross(C, p[i-1], p[i]);
			else
			{
				seg_cri(C, p[i-1], p[i], temp1, temp2);
				ans += cross(C, p[i-1], temp1);
				ang += calang(change(p[i]), temp1);
			}
		}
		else
		{
			if( dblcmp(p[i].d-R) < 0 )
			{
				seg_cri(C, p[i-1], p[i], temp1, temp2);
				ans += cross(C, temp1, p[i]);
				ang += calang(temp1, change(p[i-1]));
			}
			else
			{
				if( seg_cri(C, p[i-1], p[i], temp1, temp2) == 1 )
				{
					ang += calang(temp1, change(p[i-1]));
					ans += cross(C, temp1, temp2);
					ang += calang(change(p[i]), temp2);
				}
				else
					ang += calang(change(p[i]), change(p[i-1]));
			}
		}
	}

	ans = ans/2. + ang*R*R/2.;
	return fabs(ans);
}

point p[5010];
int t, tt, n;
int X0, Y0, P;
double s;

void Bsearch(double ll, double rr)
{
	for (int i = 0; i < 50; i++)
	{
		R = (ll + rr) / 2;
		if (s - calc(n, p, C) <= eps)
			rr = R;
		else
			ll = R;
	}
}

void solve()
{
    n = nextInt();
    for (int i = 0; i < n; i++)
    {
        p[i].x = nextDbf();
        p[i].y = nextDbf();
    }
    p[n] = p[0];
    X0 = nextInt(); Y0 = nextInt();
    P  = nextInt();
    for (int i = 0; i <= n; i++)
    {
        p[i].x -= X0;
        p[i].y -= Y0;
        p[i].d = dis(C, p[i]);
    }
    s = 0;
    for (int i = 0; i < n; i++)
		s += cross(C, p[i], p[i + 1]);
    s = fabs(s) * 0.005 * P;
	Bsearch(0, 1000);
    printf("Case %d: %.0lf\n", ++tt, R);
}

int main()
{
    C.x = C.y = 0;
    t = nextInt(); while (t--) solve();
    return 0;
}
