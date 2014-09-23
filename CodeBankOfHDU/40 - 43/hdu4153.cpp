// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 4153                                                 *
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

int main(){
    int n,w,i;
    int v[101],mark[101];//mark统计图
    int s,fen;
    int max;//记录极值
    while(cin>>n>>w,n||w){
        memset(mark,0,sizeof(mark));
        max=0;
        for(i=0;i<n;i++){
            cin>>v[i];
            mark[v[i]/w]++;
            if(max<v[i])max=v[i];//输入的数中最大的数
        }
        fen=max/w;//fen表示可以分的份数。。。
        //fen++;
        max=0;
        for(i=0;i<=fen;i++){
            if(mark[i]>max)//占份数最多。
                max=mark[i];
        }
        s=max;
        double ans;
        ans=0.01;
        for(i=0;i<=fen;i++){
            ans+=(i*1.0/fen)*(mark[fen-i]*1.0/s);
        }
        printf("%.6f\n",ans);
    }
    return 0;
}