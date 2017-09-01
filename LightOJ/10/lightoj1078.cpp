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

using namespace std;
int main(){
    int T,tt=0;
    scanf("%d",&T);
    while(T--){
        int n,k,s,i;
        scanf("%d%d",&n,&k);
        printf("Case %d: ",++tt);
        s=k%n;
        i=1;
        while(s!=0){
            s=(s*10+k)%n;
            i++;
        }
        printf("%d\n",i);
    }
    return 0;
}
