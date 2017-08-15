#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
struct node{
    double x,y;
}aa[110000];
int main()
{
     double a,d;int n;
     while(cin>>a>>d>>n){
         node s;
         s.x=0,s.y=0;
         while(d>=4*a)d-=4*a;
         for(int i=1;i<=n;i++){
             double cnt=d;
             while(cnt>0){
                 if(fabs(s.y)<eps&&s.x<a){
                     if(cnt>=a-s.x)cnt-=(a-s.x),s.x=a;
                     else s.x+=cnt,cnt=0;
                 }
                 else if(fabs(s.x-a)<eps&&s.y<a){
                     if(cnt>=a-s.y)cnt-=(a-s.y),s.y=a;
                     else s.y+=cnt,cnt=0;
                 }
                 else if(fabs(s.y-a)<eps&&s.x>0){
                     if(cnt>=s.x)cnt-=s.x,s.x=0;
                     else s.x-=cnt,cnt=0;
                 }
                 else if(fabs(s.x)<eps&&s.y>0){
                     if(cnt>=s.y)cnt-=s.y,s.y=0;
                     else s.y-=cnt,cnt=0;
                 }
                // cout<<i<<" "<<cnt<<endl;
             }
             aa[i].x=s.x;
             aa[i].y=s.y;
         }
         for(int i=1;i<=n;i++)printf("%.10lf %.10lf\n",aa[i].x,aa[i].y);
     }
     return 0;
}