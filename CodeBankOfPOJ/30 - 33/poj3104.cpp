/****
	*@author    Shen
	*@title     poj 3104
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize ("O2")

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;

const int MaxN = 100005;
int64 data[MaxN];
int64 n, k;

bool test(int val)
{
    int64 cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] > val)
        {
            cnt += (data[i] - val + k - 2) / (k - 1);
            if (cnt > val)
                return true;
        }
    }
    return false;
}

template <class _Tp>
_Tp Bsearch(_Tp l, _Tp r)
{
    _Tp mid = 0;
    while (l < r)
    {
        _Tp mid = l + (r - l) / 2;
        if (test(mid))
            l = mid + 1;
        else
            r = mid;
    }
    return mid;
}

void solve()
{
    int64 maxd = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &data[i]);
        maxd = max(data[i], maxd);
    }
    scanf("%lld", &k);
    if (k == 1)
        printf("%lld\n", maxd);
    else
        printf("%d\n", Bsearch(1LL, maxd));
}

int main()
{
    while (scanf("%lld", &n) != EOF)
        solve();
    return 0;
}
