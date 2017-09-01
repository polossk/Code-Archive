#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#pragma GCC optimize ("O7")

using namespace std;
typedef long long int64;

int sign(int64 a)
{
    if (a == 0) return 0;
    return (a > 0)? 1: -1;
}
int64 ceil(int64 a, int64 b)
{
    int s = sign(a) * sign(b);
    return b / a + (b % a != 0 && s > 0);
}
int64 floor(int64 a, int64 b)
{
    int s = sign(a) * sign(b);
    return b / a - (b % a != 0 && s < 0);
}

int64 gcd_ex(int64 a, int64 b, int64& x, int64& y)
{
    if (b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    int64 d = gcd_ex(b, a % b, x, y);
    int64 t = x; x = y;
    y = t - a / b * x;
    return d;
}

int64 x1, x2;
int64 y1, y2;
int64 a, b, c;

void solve(int tt)
{
    int64 ans = 0;
    cin >> a >> b >> c;
    cin >> x1 >> x2;
    cin >> y1 >> y2;
    printf("Case %d: ", tt);
    //#define wt(x) #x" = " << (x) << "; "
    //cout << wt(a) << wt(b) << wt(c) << endl;
    if (a == 0 && b == 0)
    {
        if (c == 0) printf("%lld\n", (x2 - x1 + 1) * (y2 - y1 + 1));
        else printf("0\n");
        return;
    }
    else if (a == 0)
    {
        if (c % b != 0){ printf("0\n"); return;}
        int64 tmp = -c / b;
        if (y1 <= tmp && tmp <= y2) printf("%lld\n", x2 - x1 + 1);
        else printf("0\n");
        return;
    }
    else if (b == 0)
    {
        if (c % a != 0){ printf("0\n"); return; }
        int64 tmp = -c / a;
        if(x1 <= tmp && tmp <= x2) printf("%lld\n", y2 - y1 + 1);
        else printf("0\n");
        return;
    }
    else
    {
        int64 r = 0, s = 0;
        int64 d = gcd_ex(a, b, r, s);
        //cout << a << " * " << r << " + " << b << " * " << s << " = " << d << endl;
        a = -a;
        if (c % d != 0){ printf("0\n"); return; }
        //cout << wt(r) << wt(s) << endl;
        if (sign(d) * sign(b) < 0) swap(x1, x2);
        if (sign(d) * sign(a) < 0) swap(y1, y2);
        int64 xmin =  ceil(b, d * x1 + c * r);
        int64 xmax = floor(b, d * x2 + c * r);
        int64 ymin =  ceil(a, d * y1 + c * s);
        int64 ymax = floor(a, d * y2 + c * s);
        //cout << wt(xmin) << wt(xmax) << endl;
        //cout << wt(ymin) << wt(ymax) << endl;
        //if (xmin > xmax) swap(xmin, xmax);
        //if (ymin > ymax) swap(ymin, ymax);
        //cout << wt(xmin) << wt(xmax) << endl;
        //cout << wt(ymin) << wt(ymax) << endl;
        int64 amin = max(xmin, ymin);
        int64 amax = min(xmax, ymax);
        //cout << wt(amin) << wt(amax) << endl;
        if (amin > amax) printf("0\n");
        else printf("%lld\n", amax - amin + 1);
    }
    return;
}

int main()
{
    int T = 0, tt = 0;
    cin >> T;
    while (T--) solve(++tt);
}
