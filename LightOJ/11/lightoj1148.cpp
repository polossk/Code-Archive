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

int c[100];
int main(){
    int T,tt=0;
    scanf("%lld",&T);
    while(T--){
        int n,i,j,k,s=0;
        scanf("%d",&n);
        for (i=0; i<n; i++)
            scanf("%d",&c[i]);
        printf("Case %d: ",++tt);
        sort(c,c+n);
        s+=c[0]+1;
        for (i=1,k=1; i<n; i++){
            if (c[i]!=c[i-1])
                s+=c[i]+1;
            else{
                k++;
                if(k>c[i]+1){
                    k=1;
                    s+=c[i]+1;
                }
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
