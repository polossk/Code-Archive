// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 2299                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
// #pragma comment(linker, "/STACK:1024000000,1024000000")

#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
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

const int MaxN = 500010;
int n, a[MaxN], num[MaxN];
int64 ans;

void merge(int num[], int l, int mid, int r)
{
    for (int k = l; k <= r; k++)
        a[k] = num[k];
    int i = l;
    int j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
            num[k] = a[j++];
        else if (j > r)
            num[k] = a[i++];
        else if (a[i] < a[j])
            num[k] = a[i++];
        else
        {
            num[k] = a[j++];
            ans += mid - i + 1;
        }
    }
}

void qsort(int num[], int l, int r)
{
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    qsort(num, l, mid);
    qsort(num, mid + 1, r);
    merge(num, l, mid, r);
}

void solve()
{
	ans = 0;
    for (int i = 0; i < n; i++)
    	num[i] = nextInt();
    qsort(num, 0, n - 1);
    printf("%lld\n", ans);
}

int main()
{
    while (scanf("%d",&n) && n) solve();
    return 0;
}
