// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   zoj 1076                                                 *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

// #include <bits/stdc++.h>
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

// gene := pair<end, begin>
// exon := pair<gene, id>
typedef pair<int, int> gene;
typedef pair<gene, int> exon;

int n;

bool operator<(const exon& a, const exon& b)
{
    return a.first.first < b. first.first;
}

void solve()
{
    #define DBG 1
    vector<exon> tasks, schedule;
    for (int i = 0; i < n; i++)
        tasks.push_back(make_pair(
            make_pair(nextInt(), nextInt()),
            i + 1)
        );
    sort(tasks.begin(), tasks.end());
    schedule.push_back(tasks[0]);
    for (int i = 1; i < n; i++)
    {
        if (schedule.back().first.first <= tasks[i].first.second)
            schedule.push_back(tasks[i]);
    }
    int sz = schedule.size();
    printf("%d", schedule[0].second);
    for (int i = 1; i < sz; i++)
        printf(" %d", schedule[i].second);
    puts("");
    #undef DBG
}

int main()
{
    while (~scanf("%d", &n) && n) solve();
    return 0;
}
