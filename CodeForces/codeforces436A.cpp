zhe/*=============================================================================
#       COPYRIGHT NOTICE
#       Copyright (c) 2014
#       All rights rserved
#
#       @author       :Shen
#       @name         :A
#       @file         :G:\My Source Code\比赛与日常练习\0613 - CF\A.cpp
#       @date         :2014-06-14 01:12
#       @algorithm    :Greedy
=============================================================================*/

#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

int n, x, tmp;
int htmp, mtmp;
typedef pair<int, int> candy;
vector<candy> a[2];
priority_queue<int> f[2];

int work(int p)
{
    int h = x, j[2] = {0, 0}, ans = 0;
    for (int i = 0; i < 2; i++)
        while (!f[i].empty())
            f[i].pop();
    while (1)
    {
        while (j[p] < a[p].size() && a[p][j[p]].first <= h)
            f[p].push(a[p][j[p]++].second);
        if (f[p].empty()) break;
        h += f[p].top(), f[p].pop();
        ans++; p ^= 1;
    }
    return ans;
}

void solve()
{
    int rs1 = 0, rs2 = 0, ans = 0;
    for (int i = 0; i < 2; i++)
        if (a[i].size() > 0)
            sort(a[i].begin(), a[i].end());
    rs1 = work(1);
    rs2 = work(0);
    ans = max(rs1, rs2);
    printf("%d\n", ans);
}

int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tmp, &htmp, &mtmp);
        a[tmp].push_back(make_pair(htmp, mtmp));
    }
    solve();
    return 0;
}
