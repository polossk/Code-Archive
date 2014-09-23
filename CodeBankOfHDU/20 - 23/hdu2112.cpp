// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   hdu 1000                                                 *
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

const int INF = 0x3f3f3f3f;
const int Max=155;

int dis[Max],res[Max][Max];
bool visit[Max];

void Dijkstra(int start,int end){
    int temp,k;
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=end;i++)
        dis[i]=res[start][i];
    dis[start]=0;
    visit[start]=1;
    for(int i=1;i<=end;i++){
        temp=INF;
        for(int j=1;j<=end;j++)
            if(!visit[j] && temp>dis[j])
                temp=dis[k=j];
        if(temp == INF) break;
        visit[k]=1;
        for(int j=1;j<=end;j++)
            if(!visit[j] && dis[j]>dis[k]+res[k][j])
                dis[j]=dis[k]+res[k][j];
    }
}

int main(){
    int num,cont;
    char s[32],e[32];
    bool flag;
    char str[32],str1[32];
    int cost;
    map<string,int>car;
    while(scanf("%d",&num)!=EOF && num!=-1){
        flag=0;
        car.clear();
        memset(res,INF,sizeof(res));
        cont=3;
        scanf("%s%s",s,e);
        if(strcmp(s,e) == 0)
            flag=1;
        car[s]=1;
        car[e]=2;
        for(int i=1;i<=num;i++){
            scanf("%s%s%d",str,str1,&cost);
            if(!car[str])
                car[str]=cont++;
            if(!car[str1])
                car[str1]=cont++;
            if(cost < res[car[str]][car[str1]])
                res[car[str]][car[str1]]=res[car[str1]][car[str]]=cost;
        }
        if(flag){
            printf("0\n");
            continue;
        }
        Dijkstra(1,cont-1);
        if(dis[2]==INF)
            printf("-1\n");
        else
            printf("%d\n",dis[2]);
    }
    return 0;
}