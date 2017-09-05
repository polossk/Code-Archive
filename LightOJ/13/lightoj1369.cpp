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

int64 a[100005];
int main(){
    int64 T,tt=0;
    scanf("%lld",&T);
    while (T--){
        int64 n,q,m,i,j,k,s=0,x,v;
        scanf("%lld%lld",&n,&q);
        for (i=0;i<n;i++){
            scanf("%lld",&a[i]);
            s+=(n-2*i-1)*a[i];
        }
        printf("Case %lld:\n",++tt);
        for (i=0;i<q;i++){
            scanf("%lld",&m);
            if (m==1)
                printf("%lld\n",s);
            else{
                scanf("%lld%lld",&x,&v);
                s-=(n-2*x-1)*a[x];
                s+=(n-2*x-1)*v;
                a[x]=v;
            }
        }
    }
    return 0;
}
