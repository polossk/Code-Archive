// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 101                                                  *
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

const bool WIN  = true;
const bool LOSE = false;
const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";

int top[25], hash[25], s[25][25];
int n;

inline int h(int pos, int lev) { return 100 * pos + lev; }

inline vector<int> getState(int a)
{
    vector<int> res(2);
    res[0] = hash[a] / 100;
    res[1] = hash[a] % 100;
    return res;
}

void init(int a)
{
    vector<int> status = getState(a);
    int pos = status[0];
    int lev = status[1];
    while (top[pos] > lev)
    {
        int tmp = s[pos][top[pos]--];
        s[tmp][++top[tmp]] = tmp;
        hash[tmp] = h(tmp, top[tmp]);
    }
}

void move(int a, int b)
{
    vector<int> status = getState(a);
    vector<int> target = getState(b);
    int pos = target[0]; // cout << "pos = " << pos << endl;
    int src = status[0]; // cout << "src = " << src << endl;
    int lev = status[1]; // cout << "lev = " << lev << endl;
    for (int i = lev; i <= top[src]; i++)
    {
        int tmp = s[src][i];
        s[pos][++top[pos]] = tmp;
        hash[tmp] = h(pos, top[pos]);
    }
    top[src] = lev - 1;
}

void printStatus()
{
    // puts("+------------------------------+");
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        // cout << top[i] << endl;
        for (int j = 0; j <= top[i]; j++)
            printf(" %d", s[i][j]);
        puts("");
    }
    // puts("+------------------------------+");
}

void solve()
{
    int a, b;
    char cmd[5], adv[5];
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++)
    {
        top[i] = 0;
        s[i][top[i]] = i;
        hash[i] = h(i, 0);
    }
    // printStatus();
    while (~scanf(" %s", cmd))
    {
        if (cmd[0] == 'q') break;
        scanf(" %d %s %d", &a, adv, &b);
        if (hash[a] / 100 == hash[b] / 100) continue;
        if (cmd[0] == 'm' && adv[1] == 'n')
        {
            init(a); init(b); move(a, b);
        }
        else if (cmd[0] == 'm' && adv[1] == 'v')
        {
            init(a); move(a, b);
        }
        else if (cmd[0] == 'p' && adv[1] == 'n')
        {
            init(b); move(a, b);
        }
        else if (cmd[0] == 'p' && adv[1] == 'v')
        {
            move(a, b);
        }
        else continue;
        // printStatus();
    }
    printStatus();
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}
