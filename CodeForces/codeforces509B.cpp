// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :                                                            *
*****************************************************************************/
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>
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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "YES";
const char nay[] = "NO";
const char ace[] = "Alice";
const char bob[] = "Bob";

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

int n, k, a[105];

void putNum(int num, int times)
{
    for (int i = 1; i < times; i++)
        printf("%d ", num);
    printf("%d", num);
}

void solve(int low, int high)
{
    puts(aye);
    for (int i = 0; i < n; i++)
    {
        putNum(1, low);
        a[i] -= low;
        for (int j = 1; j <= a[i]; j++)
            printf(" %d", j);
        puts("");
    }
}

int main()
{
    n = nextInt(); k = nextInt();
    for (int i = 0; i < n; i++)
        a[i] = nextInt();
    int l = a[0], h = a[0];
    for (int i = 0; i < n; i++)
    {
        updateMax(h, a[i]);
        updateMin(l, a[i]);
    }
    if (h - l > k) puts(nay);
    else solve(l, h);
    return 0;
}