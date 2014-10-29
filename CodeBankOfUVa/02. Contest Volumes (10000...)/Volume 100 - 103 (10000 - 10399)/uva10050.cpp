// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   uva 10050                                                *
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

const int MaxN = 128;

int party[MaxN];
bool visit[36500 +10];

void init()
{
    memset(party, 0, sizeof(party));
    memset(visit, 0, sizeof(visit));
}

void solve()
{
    init();
    int nday = nextInt();
    int nparty = nextInt();
    int max = 0;
    for (int i = 0; i < nparty; i++)
        party[i] = nextInt();
    int flag = 0;//标记是否有一的情况
    for (int i = 0; i < nparty; i++)
        if (party[i] == 1)
    {
        flag = 1; break;
    }
    if (! flag) for (int i = 1; i <= nday; i++)
    {
        if (i % 7 != 6 && i % 7)//不是休息日
            for (int j = 0; j < nparty; j++)
                if (! (i % party[j]))//第i天有人罢工
        {
            visit[i] = true; break; 
        }
    }
    if (flag) cout << nday << endl;//如果有一说明每天都有人罢工
    else
    {
        int count = 0;
        for (int i = 1; i <= nday; i++)
            if (visit[i]) count++;//统计有人罢工的天数
        cout << count << endl;
    }
}

int main()
{
    int t = nextInt();
    while(t--) solve();
    return 0;
}