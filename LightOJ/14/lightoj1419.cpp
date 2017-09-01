#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long int64;

const int64 mod = 1000000007;
int64 gcd(int64 a,int64 b)
{
    return (b==0)?a:gcd(b,a%b);
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
int64 q_mul_mod(int64 a, int64 b, int64 m = mod)
{
    a %= m; b %= m;
    int64 t = 0;
    while (b)
    {
        if (b & 1)
        {
            t+=a;
            if (t>=m)t -= m;
        }
        a <<= 1;
        if (a >= m) a -= m;
        b >>= 1;
    }
    return t;
}

int64 q_pow_mod(int64 a, int64 b, int64 m = mod)
{
    int64 ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
        {
            ans = q_mul_mod(ans, a, m);
            b--;
        }
        b /= 2;
        a = q_mul_mod(a, a, m);
    }
    return ans;
}

int64 inv(int64 n,int64 m = mod)
{
    int64 x, y;
    int64 t = gcd_ex(n, m, x, y);
    return (x % m + m) % m;
}


int64 pr[500], pcoun, phi[1005];
bool bi[1005];

void getPrime()
{
	pcoun = 1;
	pr[0] = 2;
	for(int a = 3; a <= 1000; a = a+2)
	{
		if (!bi[a])
		{
			pr[pcoun++] = a;
			for(int b = a * a; b <= 1000 ; b = b + a) bi[b]=1;
		}
	}
}

void getPhi()
{
	for (int i = 1; i <= 1000; i++)
	{
		int z = 1, y = i;
		for (int a = 0; a < pcoun; a++)
		{
			if (y % pr[a] == 0)
			{
				y = y / pr[a];
				z = z * (pr[a] - 1);
			}
		}
		phi[i] = z * y;
	}
}

int64 n, k, i;
int64 ans;

int64 ploya1(int64 n,int64 c){
    int64 sum = 0;
    //枚举n种旋转
    for(int i = 1; i <= n; i++)
        //每个循环节是m种颜色可选
        //总共有gcd(n,i)个循环节
        sum += q_pow_mod(c, gcd(n,i));
    if (n&1)
        //如果为奇数，所有位置上的循环节数量都为n/2+1
        sum += n*q_pow_mod(c, n / 2 + 1);
    else
        //否则要分奇偶，各一半
        sum += n / 2 * q_pow_mod(c, n / 2) + n / 2 * q_pow_mod(c, n / 2 + 1);
    return sum / 2 / n;
}

int64 ploya2(int64 n, int64 c)//旋转视为相同，翻转为异
{
    bool bj[1005];
    int i, j, k, x;
    int64 t = 0;
    memset(bj, 0, sizeof(bj));
    for (i = 0; i <= n - 1; i++)
    {
        for (x = j = 0; j <= n - 1; j++)
            if (!bj[ (i + j) % n ])
                for (x++, k = (i + j) % n; !bj[k]; k = (i + k) % n)
                    bj[k] = 1;
        t = t + q_pow_mod(c, x);
    }
    return t / n;
}

int64 ploya3(int64 n, int64 c)//旋转视为相同，翻转为异
{
    int x = n / 2;
    if (n % 2) x++;
    int64 t = (q_pow_mod(c, n) + q_pow_mod(c, x))/2;
    return t;
}

int64 ploya4(int64 n, int64 c)
{
    int64 ans = 0;
    for (int a = 1; a <= n; a++)
    {
        if (n%a==0)
        {
            #define dbg 0 &&
            #define wt(x) #x" = " << (x) << "; "
            dbg cout << wt(c) << wt(n / a) << endl;
            int64 tmp = q_pow_mod(c, n / a);
            dbg cout << wt(tmp) << endl;
            tmp = q_mul_mod(tmp, inv(n) % mod);
            dbg cout << wt(tmp) << endl;
            tmp = q_mul_mod(tmp, phi[a]);
            dbg cout << wt(tmp) << endl;
            ans += tmp;
            dbg cout << wt(ans) << endl;
            ans %= mod;
            dbg cout << wt(ans) << endl;
        }
    }
    dbg cout << wt(ans) << endl;
    return ans;
}

void solve(int tt)
{
    cin >> n >> k;
    ans = ploya4(n, k);
    printf("Case %d: %lld\n", tt, ans);
}

int main()
{
    getPrime(); getPhi();
    int t,tt = 0;
    cin >> t;
    while (t--) solve(++tt);
    return 0;
}
