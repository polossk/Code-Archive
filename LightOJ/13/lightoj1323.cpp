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
    int x,y;
}e[1001];
int cmp(ball a,ball b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main(){
    int T,tt=0;
    scanf("%d",&T);
    while (T--){
        int l,w,n,k,i,j,a,b;
        char s[3];
        scanf("%d%d%d%d",&l,&w,&n,&k);
        for (i=0;i<n;i++){
            scanf("%d%d%s",&a,&b,s);
            if(s[0]=='N'){
                b=(b+k)%(2*w);
                if(b<=w)
                    e[i].y=b;
                else
                    e[i].y=2*w-b;
            }
            else{
                b=(w-b+k)%(2*w);
                if(b<=w)
                    e[i].y=w-b;
                else
                    e[i].y=b-w;
            }
            if(s[1]=='W'){
                a=(l-a+k)%(2*l);
                if(a<=l)
                    e[i].x=l-a;
                else
                    e[i].x=a-l;
            }
            else{
                a=(a+k)%(2*l);
                if(a<=l)
                    e[i].x=a;
                else
                    e[i].x=2*l-a;
            }
        }
        printf("Case %d:\n",++tt);
        sort(e,e+n,cmp);
        for(i=0;i<n;i++)
            printf("%d %d\n",e[i].x,e[i].y);
    }
    return 0;
}
