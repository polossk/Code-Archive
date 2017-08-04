// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   F                                                        *
*****************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

struct cow
{
    int v, x;
    inline bool operator<(const cow& b) const { return v < b.v; }
};

const int MaxN = 32768;
int64 c1[MaxN], c2[MaxN];
cow data[MaxN];
int n;

inline int64 lowbit(int64 x) { return x & (-x); }

inline void add(int64* tree, int64 x, int64 v)
{
	for (int64 i = x; i < MaxN; i += lowbit(i)) tree[i] += v;
}

int64 get(int64* tree, int64 x)
{
    int64 sum = 0;
	for (int64 i = x; i > 0; i -= lowbit(i)) sum += tree[i];
	return sum;
}

void solve()
{
    fill(c1, c1 + MaxN, 0);
    fill(c2, c2 + MaxN, 0);
    for (int i = 1; i <= n; i++)
    {
        data[i].v = nextInt();
        data[i].x = nextInt();
    }
    sort(data + 1, data + n + 1);
    int64 tot = 0, maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        updateMax(maxx, (int64)data[i].x);
        add(c1, data[i].x, 1LL);
        add(c2, data[i].x, data[i].x);
        int64 tmp = get(c2, maxx);
        int64 sum1 = get(c1, data[i].x);
        int64 sum2 = get(c2, data[i].x);
        int64 A = sum1 * data[i].x - sum2;
        int64 B = tmp - sum2;
        int64 C = (int64(i) - sum1) * data[i].x;
        tot += (A + B - C) * data[i].v;
    }
    cout << tot << endl;
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}
