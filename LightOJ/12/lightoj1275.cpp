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

int main(){
    int T,tt=0;
    scanf("%d",&T);
    while (T--){
        int n,i,a,j,k,s=0,b;
        scanf("%d%d",&a,&b);
        printf("Case %d: ",++tt);
        if (a==0||b==0)
            printf("%d\n",0);
        else{
            if (b%(2*a)==0)
                printf("%d\n",b/(2*a));
            else{
                printf("%d\n",(int)(1.0*b/2/a+0.499999));
            }
        }
    }
    return 0;
}
