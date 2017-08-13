// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   codeforces 388B                                          *
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

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

const int MAXN = 40;
const int MAXS = 1024;

bool a[MAXS][MAXS];
int v, id[MAXN][MAXN];

void addedge(int u, int v)
{
    a[u][v] = a[v][u] = true;
}

void init()
{
    v = 2; id[0][0] = 0;
    for (int i = 1; i <= 30; i++)
        for (int j = 0; j < i + 1; j++)
            id[i][j] = v++;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < i + 1; j++)
            addedge(id[i][j], id[i + 1][j]);
        for (int j = 0; j < i + 1; j++)
            addedge(id[i][j], id[i + 1][i + 1]);
    }
}

int main()
{
    init(); int k = nextInt();
    for (int i = 0; i < 30; i++)
    {
        if (k & (1 << i)) addedge(id[30][i + 1], 1);
    }
    cout << v << endl;
    for (int i = 0; i < v; i++)
    {
        string s;
        for (int j = 0; j < v; j++)
            s += a[i][j] ? 'Y' : 'N';
        cout << s << endl;
    }
    return 0;
}
// g++ F.cpp -o F.exe -std=c++11