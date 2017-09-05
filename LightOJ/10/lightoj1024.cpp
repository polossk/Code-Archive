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
int c[10001];//记录最大因子个数
int d[10001],m;//记录大数和数长
void mul(int t){
    int i,j,k,temp=0;
    for(i=0;i<m;i++)
        d[i]*=t;
    for (i=0;i<m;i++){
        k=d[i]+temp;
        temp=k/10;
        d[i]=k%10;
    }
    while (temp){
        d[m]=temp%10;
        temp=temp/10;
        m++;
    }
}
int main(){
    int T,tt=0;
    scanf("%d",&T);
    while (T--){
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        int n,i,j,k,t;
        scanf("%d",&n);
        while (n--){
            scanf("%d",&t);
            i=2;
            while (t!=1){
                k=0;
                if (t%i==0){
                    t=t/i;
                    k++;
                    while(t%i==0){t=t/i;k++;}
                }
                c[i]=max(c[i],k);
                i++;
            }
        }
        d[0]=m=1;
        for (i=2;i<10000;i++){
            if (c[i]==0)
                continue;
            t=(int)pow(i,c[i]);
            //printf("%d\n",t);
            mul(t);
        }
        printf("Case %d: ",++tt);
        for (i=m-1;i>=0;i--)
            printf("%d",d[i]);
        printf("\n");
    }
    return 0;
}
