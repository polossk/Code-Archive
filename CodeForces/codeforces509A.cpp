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
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

int t[11][11];

void build()
{
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            t[i][j] = 1;
    for (int i = 2; i < 11; i++)
        for (int j = 2; j < 11; j++)
            t[i][j] = t[i - 1][j] + t[i][j - 1];

}

int main()
{
    build();
    int n = nextInt();
    cout << t[n][n] << endl;
    return 0;
}