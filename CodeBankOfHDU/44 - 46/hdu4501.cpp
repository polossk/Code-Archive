// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4501                                                 *
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

const int mm=110;
int dp[mm][mm][11];
struct node{
    int a,b,c;
}f[mm];
int n,v1,v2,kk;

int main(){
    while(scanf("%d%d%d%d",&n,&v1,&v2,&kk)!=EOF){
        for(int i=0; i<n; ++i)
            scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
        memset(dp,0,sizeof(dp));
        int z,ans=0,tmp;
        for(int i=0;i<n;i++){
            for(int j=v1;j>=0;--j)
                for(int k=v2;k>=0;--k)
                    for(int l=kk;l>=0;--l){
                        tmp=0;
                        if(j-f[i].a>=0)
                            updateMax(tmp,dp[j-f[i].a][k][l]+f[i].c);
                        if(k-f[i].b>=0)
                            updateMax(tmp,dp[j][k-f[i].b][l]+f[i].c);
                        if(l-1>=0)
                            updateMax(tmp,dp[j][k][l-1]+f[i].c);
                        updateMax(dp[j][k][l],tmp);
                    }
        }
        printf("%d\n",dp[v1][v2][kk]);
    }
}