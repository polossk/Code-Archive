/****
	*@author    Shen
	*@title     B
	*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct city
{
    int x, y, p;
    double dist;
    city(){}
    void calcDistance()
    {
        dist = sqrt(double(x * x + y * y));
    }
};

bool operator<(const city& a, const city& b)
{
    return a.dist < b.dist;
}

city data[1005];
const int sup = 1000000;
int n, s;

void solve()
{
    int _x = 0, _y = 0, _p = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &data[i].x, &data[i].y, &data[i].p);
        data[i].calcDistance();
    }
    sort(data, data + n);
    double ans = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        s += data[i].p;
        ans = data[i].dist;
        if (s >= sup)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("%.7lf\n", ans);
    else puts("-1");
}

int main()
{
    while (~scanf("%d%d", &n, &s))
        solve();
    return 0;
}
