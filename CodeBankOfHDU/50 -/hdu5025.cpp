// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 5025                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
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

const char nay[] = "impossible";
const int MaxN = 105;
const int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

struct node
{
    int x, y, key, state, step;
    void tSnake(const node& tmp, int now)
    {
        x = tmp.x; y = tmp.y; key = tmp.key;
        state = now;
        step = tmp.step + 1;
    }
    void tKey(const node& tmp, int i)
    {
        x = tmp.x + dir[i][0];
        y = tmp.y + dir[i][1];
        key = tmp.key + 1;
        state = tmp.state;
        step = tmp.step + 1;
    }
    void tMove(const node& tmp, int i)
    {
        x = tmp.x + dir[i][0];
        y = tmp.y + dir[i][1];
        key = tmp.key;
        state = tmp.state;
        step = tmp.step + 1;
    }
};

int n, m, k, sx, sy;
int hash[10];
bool vis[MaxN][MaxN][11][40];
int id[MaxN][MaxN];
char g[MaxN][MaxN];

inline bool inMap(const int& x, const int& y)
{
    return x >= 0 && x < n && y >= 0 && y < n && g[x][y] != '#';
}

int bfs()
{
    queue<node> q;
    node cur, next;
    cur.x = sx; cur.y = sy;
    cur.step = cur.state = cur.key = 0;
    memset(vis, 0, sizeof(vis));
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        // snake
        if (g[cur.x][cur.y] == 'S')
        {
            int idnow = id[cur.x][cur.y];
            if (!(cur.state & (1 << idnow)))
            {
                int now = cur.state | (1 << idnow);
                if (!vis[cur.x][cur.y][cur.key][now])
                {
                    vis[cur.x][cur.y][cur.key][now] = 1;
                    next.tSnake(cur, now);
                    q.push(next);
                }
                continue;
            }
        }
        // move
        for (int i = 0; i < 4; i++)
        {
            int xx = cur.x + dir[i][0];
            int yy = cur.y + dir[i][1];
            if (inMap(xx, yy))
            {
                // Monk Tang
                if (g[xx][yy] == 'T' && cur.key == k)
                    return cur.step + 1;
                // key
                else if (g[xx][yy] == '0' + cur.key + 1
                    && !vis[xx][yy][cur.key + 1][cur.state])
                {
                    vis[xx][yy][cur.key + 1][cur.state] = 1;
                    next.tKey(cur, i);
                    q.push(next);
                }
                // empty
                else if (!vis[xx][yy][cur.key][cur.state])
                {
                    vis[xx][yy][cur.key][cur.state] = 1;
                    next.tMove(cur, i);
                    q.push(next);
                }

            }
        }
    }
    return -1;
}

void solve()
{
    m = 0;
    memset(id, 0, sizeof(id));
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
        g[i][j] = nextChr();
        if (g[i][j] == 'K') sx = i, sy = j;
        else if (g[i][j] >= '0' && g[i][j] <= '9')
            hash[g[i][j] - '0'] = 1;
        else if (g[i][j] == 'S') id[i][j] = m++;
    }
    int flag = 0;
    for (int i = 1; i <= k; i++) if (hash[i] != 1)
    {
        flag = 1;
        break;
    }
    if (flag) { puts(nay); return; }
    int ans = bfs();
    if (bfs() == -1) puts(nay);
    else printf("%d\n", ans);
}

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        if (n == 0 && k == 0) return 0;
        solve();
    }
    return 0;
}
