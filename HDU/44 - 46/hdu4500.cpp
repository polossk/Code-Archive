// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4500                                                 *
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

int a[30][30];
int s[30][30];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0)break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&a[i][j]);
                s[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0){
                    if(a[i-1][j]*a[i][j]<0) s[i][j]+=abs(a[i-1][j]);
                    else s[i][j]-=abs(a[i-1][j]);
                }
                if(i<n-1){
                    if(a[i+1][j]*a[i][j]<0) s[i][j]+=abs(a[i+1][j]);
                    else s[i][j]-=abs(a[i+1][j]);
                }
                if(j>0){
                    if(a[i][j-1]*a[i][j]<0) s[i][j]+=abs(a[i][j-1]);
                    else s[i][j]-=abs(a[i][j-1]);
                }
                if(j<m-1){
                    if (a[i][j+1]*a[i][j]<0) s[i][j]+=abs(a[i][j+1]);
                    else s[i][j]-=abs(a[i][j+1]);
                }
            }
        }
        int Max=-100000;
        int x,y;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (Max<s[i][j]){
                    Max=s[i][j];
                    x=i+1;
                    y=j+1;
                }
            }
        }
        printf("%d %d %d\n",x,y,Max);
    }
    return 0;
}