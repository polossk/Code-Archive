// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 1372                                                 *
*****************************************************************************/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
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

int dx[] = { 1,  2,  2,  1, -1, -2, -2, -1};
int dy[] = { 2,  1, -1, -2, -2, -1,  1,  2};
int step[8][8], fa[8][8];
bool vis[8][8];

inline bool inbound(int x, int l, int r) { return l <= x && x < r; }

inline bool inbound(int u)
{
    int x = u / 8, y = u % 8;
    return inbound(x, 0, 8) && inbound(y, 0, 8);
}

inline int encode(int x, int y) { return x * 8 + y; }

inline int newPos(int old, int method)
{
    int x = old / 8, y = old % 8;
    x += dx[method], y += dy[method];
    if (inbound(x, 0, 8) && inbound(y, 0, 8)) return encode(x, y);
    else return -1;
}

inline void print(int u)
{
    int x = u / 8, y = u % 8;
    printf("(%d, %d)", x, y);
}

inline void bprint()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            printf("%c", vis[i][j]? '#': 'O');
        puts("");
    }
    puts("");
}

inline int getx(string s) { return int(s[0] - 'a'); }

inline int gety(string s) { return int(s[1] - '1'); }

void path_print(int t)
{
    stack<int> pos; int tmp = t;
    while (true)
    {
        int fx = fa[t / 8][t % 8] / 8;
        int fy = fa[t / 8][t % 8] % 8;
        if (fx == t / 8 && fy == t % 8) break;
        pos.push(encode(fx, fy));
        t = encode(fx, fy);
    }
    while (!pos.empty())
    {
        print(pos.top()); printf(" -> ");
        pos.pop();
    }
    print(tmp); puts("");
}

int bfs(string _beg, string _tar)
{
    int beg = encode(getx(_beg), gety(_beg));
    int tar = encode(getx(_tar), gety(_tar));
    //print(beg); print(tar);
    //puts("");
    memset(step, 0, sizeof(step));
    memset(vis, 0, sizeof(vis));
    memset(fa, 0, sizeof(fa));
    queue<int> q; q.push(beg); vis[beg / 8][beg % 8] = 1;
    fa[beg / 8][beg % 8] = beg;
    while (!q.empty())
    {
        //bprint();
        int top = q.front(); q.pop();
        if (top == tar) break;
        for (int j = 0; j < 8; j++)
        {
            int tmp = newPos(top, j);
            //print(top); cout << " -> "; print(tmp); system("pause");
            if (tmp != -1 && inbound(tmp) && !vis[tmp / 8][tmp % 8])
            {
                vis[tmp / 8][tmp % 8] = 1;
                step[tmp / 8][tmp % 8] = step[top / 8][top % 8] + 1;
                fa[tmp / 8][tmp % 8] = top;
                q.push(tmp);
            }
        }
    }
    //path_print(tar);
    return step[tar / 8][tar % 8];
}

int main()
{
    string b, t;
    while (cin >> b >> t)
        printf("To get from %s to %s takes %d knight moves.\n", b.c_str(), t.c_str(), bfs(b, t));
    return 0;
}