/****
	*@Polo-shen
	*
	*/
#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
//#include <cmath>
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

int c[100],f[100001];
int main(){
    int T,tt=0;
    scanf("%lld",&T);
    while (T--){
        int n,i,j,k,s=0;
        scanf("%d%d",&n,&k);
        printf("Case %d: ",++tt);
        f[0]=0;
        for (i=2;i<=n;i++)
            f[i]=(f[i-1]+k)%i;
        printf("%d\n",f[n]+1);
    }
    return 0;
}
