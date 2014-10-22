// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   poj 3537                                                 *
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

const char aye[] = "Yes";
const char nay[] = "No";
const char ace[] = "Alice";
const char bob[] = "Bob";
const bool WIN  = true;
const bool LOSE = false;

const int MaxN = 2048;
int n, sg[MaxN];
bool temp[MaxN];

inline void buildSG()
{
    sg[0] = 0;
    sg[1] = sg[2] = sg[3] = 1;
    sg[4] = sg[5] = 2;
    for (int i = 6; i < MaxN; i++)
    {
        memset(temp, 0, sizeof(temp));
        temp[sg[i - 3]] = WIN;
        temp[sg[i - 4]] = WIN;
        temp[sg[i - 5]] = WIN;
        for (int j = 1; j * 2 <= i - 5; j++)
            temp[sg[j] ^ sg[i - 5 - j]] = WIN;
        for (int j = 0; j < MaxN; j++) if (!temp[j])
        {
            sg[i] = j;
            break;
        }
    }
}

int main()
{
    buildSG();
    while (~scanf("%d", &n))
        printf("%d\n", sg[n]? 1: 2);
    return 0;
}
