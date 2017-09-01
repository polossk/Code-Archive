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
int64 p[13],r[13],n;
void gcd(int64 a,int64 b,int64 &d,int64 &x,int64 &y){
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int64 Chinese_Remainder(){
    int64 i,s=1,m,x,y,d,ans=0;
    for (i=0;i<n;i++)
        s=s*p[i];
    for (i=0;i<n;i++)
    {
        m=s/p[i];
        gcd(p[i],m,d,x,y);
        ans=(ans+y*m*r[i])%s;
	}
    return (ans%s+s)%s;
}
int main(){
    int64 T,t,tt=0,i;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld%lld",&p[i],&r[i]);
        t=Chinese_Remainder();
        printf("Case %lld: %lld\n",++tt,t);
    }
    return 0;
}
