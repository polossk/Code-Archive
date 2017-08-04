#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct Elem
{
    int a, b;
    bool operator<=(const Elem &x)
    {
        return this->a * (long long) x.b <= x.a * (long long) this->b;
    }
    bool operator<(const Elem &x)
    {
        return this->a * (long long) x.b < x.a * (long long) this->b;
    }
    Elem operator-(const Elem &x)
    {
        Elem ret;
        ret.a = this->a * x.b - x.a * this->b;
        ret.b = this->b * x.b;
        return ret;
    }
} s;

int n, m;

Elem binarysearch(int a)
{
    Elem ret;
    ret.b = a;
    int l = 1, r = 5000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid * m > n * a) r = mid;
        else l = mid + 1;
    }
    ret.a = l;
    return ret;
}

int main()
{
    bool first = true;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (first) first = false;
        else putchar('\n');
        s.a = 5000;
        s.b = 1;
        Elem y; y.a = n; y.b = m;
        for (int i = 1; i <= m; i++)
        {
            Elem x = binarysearch(i);
            Elem z = x; z.a--;
            if ((x - y) <= (y - z)) z = x;
            Elem temp = z - y;
            if (temp.a < 0) temp.a = -temp.a;
            if (temp < s)
            {
                s = temp;
                printf("%d/%d\n", z.a, z.b);
            }
        }
    }
    return 0;
}