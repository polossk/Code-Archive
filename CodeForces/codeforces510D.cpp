// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   B                                                        *
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

int l[306];
int c[306];

int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
map<int, int>mp[2];
map<int, int>::iterator it;

int pre, cur;

void setMin(int x,int y)
{
    if (mp[cur].count(x))
        updateMin(mp[cur][x], y);
    else mp[cur][x]=y;
}
int main()
{
    int n = nextInt();
    for (int i = 1; i <= n; i++) l[i] = nextInt();
    for (int i = 1; i <= n; i++) c[i] = nextInt();
    pre = 0; cur = 1;
    mp[0][l[1]] = c[1];
    for (int i = 2; i <= n; i++)
    {
        mp[cur].clear();
        mp[cur][l[i]]=c[i];
        for (it = mp[pre].begin(); it != mp[pre].end(); it++)
        {
            int x = it -> first;
            int y = it -> second;
            setMin(x, y);
            setMin(gcd(x, l[i]), y + c[i]);
        }
        swap(pre, cur);
    }
    if (!mp[pre].count(1))
        puts("-1");
    else
        printf("%d\n", mp[pre][1]);
    return 0;
}