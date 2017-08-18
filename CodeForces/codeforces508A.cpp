// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   A                                                        *
*****************************************************************************/

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

const int MaxN = 1024;
bool grid[MaxN][MaxN];
int n, m, k;

inline bool isBlack(int i, int j)
{
    return grid[i][j] && grid[i + 1][j]
        && grid[i][j + 1] && grid[i + 1][j + 1];
}

inline bool isComp(int i, int j)
{
    bool flag = false;
    if (i < n && j < m) flag |= isBlack(i, j);
    if (i > 1 && j < m) flag |= isBlack(i - 1, j);
    if (j > 1 && i < n) flag |= isBlack(i, j - 1);
    if (i > 1 && j > 1) flag |= isBlack(i - 1, j - 1);
    return flag;
}

void solve()
{
    n = nextInt();
    m = nextInt();
    k = nextInt();
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int a = nextInt();
        int b = nextInt();
        grid[a][b] = 1;
        if (i >= 3 && isComp(a, b))
        {
            printf("%d\n", i + 1);
            return;
        }
    }
    puts("0");
}

int main()
{
    solve();
    return 0;
}