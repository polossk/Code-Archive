// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 1000                                                 *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
typedef double DB;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

namespace Geo{
    #define typec double
    const typec eps=1e-8;
    int dblcmp(double d){
        if (fabs(d)<eps)return 0;
        return d>eps?1:-1;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
    struct Point2D{
        typec x,y;
        Point2D(){}
        Point2D(typec _x,typec _y):x(_x),y(_y){};
        void input(){
            scanf("%lf%lf",&x,&y);
        }
        void output(){
            printf("%.2f %.2f\n",x,y);
        }
        bool operator==(Point2D a)const{
            return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
        }
        bool operator<(Point2D a)const{
            return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
        }
        typec len(){
            return hypot(x,y);
        }
        typec len2(){
            return x*x+y*y;
        }
        Point2D operator + (const Point2D &A) const{
            return Point2D(x + A.x , y + A.y);
        }
        Point2D operator - (const Point2D &A) const{
            return Point2D(x - A.x , y - A.y);
        }
        Point2D operator * (const typec _x) const{
            return Point2D(x * _x , y * _x);
        }
        typec operator * (const Point2D &A) const{
            return x * A.x + y * A.y;
        }
        typec operator ^ (const Point2D &A) const{
            return x * A.y - y * A.x;
        }
        Point2D operator / (const typec _p) const{
            return Point2D(x / _p , y / _p);
        }
        typec distance(Point2D p){
            return hypot(x-p.x,y-p.y);
        }
        Point2D add(Point2D p){
            return Point2D(x+p.x,y+p.y);
        }
        Point2D sub(Point2D p){
            return Point2D(x-p.x,y-p.y);
        }
        Point2D mul(typec b){
            return Point2D(x*b,y*b);
        }
        Point2D div(typec b){
            return Point2D(x/b,y/b);
        }
        typec dot(Point2D p){
            return x*p.x+y*p.y;
        }
        typec det(Point2D p){
            return x*p.y-y*p.x;
        }
        typec rad(Point2D a,Point2D b){
            Point2D p=*this;
            return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
        }
        Point2D trunc(typec r){
            typec l=len();
            if (!dblcmp(l))return *this;
            r/=l;
            return Point2D(x*r,y*r);
        }
        Point2D rotleft(){
            return Point2D(-y,x);
        }
        Point2D rotright(){
            return Point2D(y,-x);
        }
        Point2D rotate(Point2D p,typec angle)//è&#198;μ&#227;p&#196;&#230;ê±&#213;&#235;Dy×aangle&#189;&#199;&#182;è
        {
            Point2D v=this->sub(p);
            typec c=cos(angle),s=sin(angle);
            return Point2D(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
        }
    };

    typec cross(Point2D a,Point2D b,Point2D c){
        return (b.sub(a)).det(c.sub(a));
    }
}using namespace Geo;
/* .................................................................................................................................. */
double a , b , c , l , r;
DB f0(DB x){    // Input the function
    return sqrt(1. + sqr(2. * a * x + b));
}

/* helper function of adaptive_simpsons */
DB adaptive_simpsons_aux(DB (*f)(DB), DB a, DB b,
    DB eps, DB s, DB fa, DB fb, DB fc, int depth) {
  DB c = (a + b) / 2, h = b - a;
  DB d = (a + c) / 2, e = (c + b) / 2;
  DB fd = f(d), fe = f(e);
  DB sl = (fa + 4 * fd + fc) * h / 12;
  DB sr = (fc + 4 * fe + fb) * h / 12;
  DB s2 = sl + sr;
  if (depth <= 0 || fabs(s2 - s) <= 15 * eps)
    return s2 + (s2 - s) / 15;
  return adaptive_simpsons_aux(f, a, c, eps / 2, sl, fa, fc, fd, depth - 1) +
         adaptive_simpsons_aux(f, c, b, eps / 2, sr, fc, fb, fe, depth - 1);
}

/* Adaptive Simpson's Rule, integral of f at [a, b],
 * max error of eps, max depth of depth */
DB adaptive_simpsons(DB (*f)(DB), DB a, DB b,
    DB eps, int depth) {
  DB c = (a + b) / 2, h = b - a;
  DB fa = f(a), fb = f(b), fc = f(c);
  DB s = (fa + 4 * fc + fb) * h / 6;
  return adaptive_simpsons_aux(f, a, b, eps, s, fa, fb, fc, depth);
}

DB f(DB x){
    return a * x * x + b * x + c;
}
int n;
const int N = 2e4 + 9;
Point2D p[N];
vector<DB> h;
bool inSeg(Point2D l , Point2D r , Point2D mid){
    return dblcmp(mid.x - fmin(l.x , r.x)) >= 0
        && dblcmp(fmax(l.x , r.x) - mid.x) >= 0
        && dblcmp(mid.y - fmin(l.y , r.y)) >= 0
        && dblcmp(fmax(l.y , r.y) - mid.y) >= 0;
}
bool check(Point2D pre , Point2D now , Point2D nex){
    pre = pre - now;
    nex = nex - now;
    pre = pre.trunc(0.1);
    nex = nex.trunc(0.1);
    pre = pre + now;
    nex = nex + now;
    if(dblcmp(pre.y - f(pre.x)) * dblcmp(nex.y - f(nex.x)) < 0) return true;
    return false;
}
void solve(){
    scanf("%lf%lf%lf%lf%lf" , &a , &b , &c , &l , &r);
    for (int i = 0 ; i < n ; ++i) p[i].input();

    h.resize(0);
    if (n <= 2){
        puts("0.00");
        return;
    }
    for (int i = 0 ; i < n ; ++i){
        Point2D now , nex , pre , Inter , Inter2;
        pre = p[(i + n - 1) % n];
        now = p[i];
        nex = p[(i + 1) % n];
//        if (now == nex) continue;
        if (dblcmp(now.x - nex.x) == 0){
            Inter = Point2D(now.x , f(now.x));
            if (inSeg(now , nex , Inter)) {

                    h.PB(Inter.x);

                    if (Inter == now) {

                            if (!check(pre , now , nex)){
                                  h.PB(Inter.x);
                            }
                    }
            }
        }
        else{
            DB kk = (nex.y - now.y) / (nex.x - now.x);
            DB bb = nex.y - nex.x * kk;
            DB A = sqr(b - kk) - 4. * (c - bb) * a;
            if (dblcmp(A) > 0){
                DB x1 = (-(b - kk) + sqrt(A)) / 2. / a;
                DB x2 = (-(b - kk) - sqrt(A)) / 2. / a;
                Inter = Point2D(x1 , f(x1));
                Inter2 = Point2D(x2 , f(x2));
                if (inSeg(now , nex , Inter)) {
                    if (!(Inter == pre) && !(Inter == nex))h.PB(Inter.x);
                    if (Inter == now && !check(pre , now , nex)) h.PB(Inter.x);
                }
                if (inSeg(now , nex , Inter2)) {
                    if (!(Inter2 == pre) && !(Inter2 == nex))h.PB(Inter2.x);
                    if (Inter2 == now && !check(pre , now , nex))h.PB(Inter2.x);
                }
            }
        }
    }
    sort(ALL(h));
    DB ans = 0;
    for (int i = 0 ; i + 1 < SZ(h) ; i += 2){
        DB L = fmax(l , h[i]) , R = fmin(h[i + 1] , r);
        if (dblcmp(R - L) > 0){
            ans += adaptive_simpsons(f0 , L , R , eps , 10);
//            ans += simpson(f0 , L , R);
//            ans += romberg(f0 , L , R );
        }
        if (dblcmp(R - L) < 0) break;
    }
    double out = ans;
    printf("%.2lf\n" , out + eps);
}
int main()
{
    while(~scanf("%d" , &n)) solve();
}