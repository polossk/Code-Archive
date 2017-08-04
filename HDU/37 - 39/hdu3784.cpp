// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 3784                                                 *
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

int a[1005];
bool flag[1005];

int main(){
    int n;
    while (cin>>n && n){
        memset(flag,0,sizeof(flag));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            flag[a[i]]=1;
        }
        for (int i=0;i<n;i++)
        {
            int t;
            t=a[i];
            if (!flag[t])continue;
            while (t>1)
            {
                if (t&1){ t=t*3+1; t/=2; }
                else t/=2;
                if (t<=1000) flag[t]=0;
            }
        }
        bool blkflag=1;
        for(int i=n-1;i>=0;i--) if (flag[a[i]])
        {
            if (blkflag==1)
            {
                printf("%d",a[i]);
                blkflag = 0;
            }
            else printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}