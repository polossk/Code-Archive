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

#define pos 1e-12
int64 x[707],y[707];
int64 e[500000];
int main(){
    int64 T,tt=0;
    scanf("%lld",&T);
    while (T--){
        int64 i,j,k,t=0,s=1,n;
        scanf("%lld",&n);
        for (i=0;i<n;i++){
            scanf("%lld%lld",&x[i],&y[i]);
            for (j=0;j<i;j++){
                e[t++]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            }
        }
        sort(e,e+t);
        for (i=1;i<t;i++)
            if (e[i]-e[i-1]!=0)
                s++;
        printf("Case %lld: %lld\n",++tt,s+1);
    }
    return 0;
}
