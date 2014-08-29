#include <cstdio>
using namespace std;
typedef long long int64;

int64 gcd(int64 a, int64 b)
{
    return (b == 0)? a: gcd(b, a % b);
}

int64 mul(int64 a, int64 b)
{
    int64 t = 0;
    while (b)
    {
        if (b & 1) t += a;
        a <<= 1; b >>= 1;
    }
    return t;
}

int64 pow(int64 a, int64 b)
{
    int64 ans = 1;
    while (b)
    {
        if (b & 1) { ans = mul(ans, a); b--; }
        b >>= 1; a = mul(a, a);
    }
    return ans;
}

int main()
{
    int n, k, i;
    int64 ans;
    while (~scanf("%d%d", &k, &n) && n && k)
    {
        if (n & 1)
            ans = pow(k, n / 2 + 1) * n;
        else
            ans = pow(k, n / 2 + 1) * (n / 2)
                  + pow(k, n / 2) * (n / 2);
        for (i = 1; i <= n; i++)
            ans += pow(k, gcd(n, i));
        ans = printf("%I64d\n", ans / (2 * n));
    }
    return 0;
}
