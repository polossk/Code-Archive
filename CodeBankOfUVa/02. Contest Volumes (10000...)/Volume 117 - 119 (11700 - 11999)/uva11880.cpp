/****
	*@PoloShen
	*Title:G
	*/
#include <cstdio>
#include <cmath>
using namespace std;

const double eps =1e-8;
const double pi = 2 * asin(1.0);
double l, w, x, y, r, a, v, s;
double px, py;

void solve(){
    l -= r; w -= r;
    px = x + v * cos(a / 180 * pi) * s;
    py = y + v * sin(a / 180 * pi) * s;
    while (r - px > eps || px - l > eps){
        if (r - px > eps) px = (r - px) + r;
        else px = -(px - l) + l;
    }
    while (r - py > eps || py - w > eps){
        if (r - py > eps) py = (r - py) + r;
        else py = -(py - w) + w;
    }
    printf("%.2lf %.2lf\n", px, py);
}

int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&l,&w,&x,&y,&r,&a,&v,&s),r!=0)
        solve();
    return 0;
}