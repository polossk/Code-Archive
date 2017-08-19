// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :                                                            *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
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

inline int64 gcd(int64 a, int64 b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

inline int64 lcm(int64 a, int64 b)
{
    return a / gcd(a, b) * b;
}

int64 t, w, b, p = 0;

void solve()
{
    w = next64d();
    b = next64d();
    if (w > b) swap(w, b);
    int64 hoge = gcd(w, b);
    if (t / (w / hoge) < b)
        p = min(w - 1, t);
    else
    {
        int64 piyo = lcm(w, b);
        p = t / piyo * w - 1 + (min(t % piyo + 1, w));
    }
    int64 d = gcd(p, t);
    cout << p / d << '/' << t / d << endl;
}

int main()
{
    while (cin >> t) solve();
    return 0;
}