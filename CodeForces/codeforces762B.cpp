// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   Educational Codeforces Round 17 B                        *
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

typedef pair<int64, bool> Mouse;
bool operator>(const Mouse& a, const Mouse& b)
{
    return a.first < b.first;
}

int a, b, c, m;

priority_queue<Mouse, vector<Mouse>, greater<Mouse> > table;

int main()
{
    cin >> a >> b >> c >> m;
    for (int i = 0; i < m; i++)
    {
        int _ = nextInt();
        table.push(make_pair(_, nextStr()[0] == 'U'));
    }
    int cnt = 0; int64 cost = 0;
    while (!table.empty())
    {
        auto check = table.top(); table.pop();
        if (check.second)
        {
            if (a > 0) { a --; cnt ++; cost += check.first; }
            else if (c > 0) { c --; cnt ++; cost += check.first; }
            else continue;
        }
        else
        {
            if (b > 0) { b --; cnt ++; cost += check.first; }
            else if (c > 0) { c --; cnt ++; cost += check.first; }
            else continue;
        }
    }
    cout << cnt << " " << cost << endl;
    