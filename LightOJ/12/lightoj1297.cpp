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
    while(T--){
        double w,l,t,d;
        scanf("%lf%lf",&w,&l);
        printf("Case %d: ",++tt);
        d=16*(w+l)*(w+l)-48*w*l;
        t=(4*(w+l)-sqrt(d))/24.0;
        printf("%lf\n",(w-2*t)*(l-2*t)*t);
    }
    return 0;
}
