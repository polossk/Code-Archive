// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   LightOJ 1212                                             *
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

int t, tt, n, m;

void solve()
{
    printf("Case %d:\n", ++tt);
    n = nextInt(); m = nextInt();
    deque<int> d; string order; int val;
    while (m--)
    {
        order = nextStr();
        if (order == "popLeft"){
            if (d.empty())
                printf("The queue is empty\n");
            else
            {
                printf("Popped from left: %d\n", d.front());
                d.pop_front();
            }
        }
        else if (order == "popRight"){
            if (d.empty())
                printf("The queue is empty\n");
            else
            {
                printf("Popped from right: %d\n", d.back());
                d.pop_back();
            }
        }
        else if (order == "pushLeft"){
            val = nextInt();
            if (d.size() == n)
                printf("The queue is full\n");
            else
            {
                d.push_front(val);
                printf("Pushed in left: %d\n", val);
            }
        }
        else if (order == "pushRight"){
            val = nextInt();
            if (d.size() == n)
                printf("The queue is full\n");
            else
            {
                d.push_back(val);
                printf("Pushed in right: %d\n", val);
            }
        }
        else continue;
    }
    return;
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
