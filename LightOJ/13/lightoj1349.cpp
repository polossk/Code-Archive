/****
	*@Polo-shen
	*
	*/
#include <iostream>
//#include <iomanip>
//#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
//#include <set>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

struct ball{
    int64 x,y,w;
}e[50005];
int64 cmp_x(ball a,ball b){
    return a.x<b.x;
}
int64 cmp_y(ball a,ball b){
    return a.y<b.y;
}
int main(){
    int64 T,tt=0;
    scanf("%lld",&T);
    while (T--){
        int64 n,m,q,i,j,k,u,v,w,s=0,x,y,num=0;
        scanf("%lld%lld%lld",&n,&m,&q);
        for (i=0;i<q;i++){
            scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].w);
            num+=e[i].w;
        }
        num=(num+1)/2;
        sort(e,e+q,cmp_x);
        for (i=0;i<q;i++){
            s+=e[i].w;
            if (s>=num){
                x=e[i].x;
                break;
            }
        }
        s=0;
        sort(e,e+q,cmp_y);
        for (i=0;i<q;i++){
            s+=e[i].w;
            if (s>=num){
                y=e[i].y;
                break;
            }
        }
        printf("Case %lld: %lld %lld\n",++tt,x,y);
    }
    return 0;
}
