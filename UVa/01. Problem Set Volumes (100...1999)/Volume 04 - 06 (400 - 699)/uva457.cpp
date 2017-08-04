/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

int main(){
    int n,k;
    scanf("%d",&n);
    for (k=1;k<=n;k++){
        int DNA[10];
        int i,j;
        for (i=0;i<=9;i++)
            scanf("%d",&DNA[i]);
        int now[50]={0},old[50];
        now[20]=1;
        for (i=1;i<=50;i++){
            for (j=1;j<=40;j++){
                if (now[j]==0) printf(" "); else
                if (now[j]==1) printf("."); else
                if (now[j]==2) printf("x"); else
                printf("W");
            }
            printf("\n");
            memcpy(old,now,sizeof(old));
            for (j=1;j<=40;j++)
                now[j]=DNA[old[j-1]+old[j]+old[j+1]];
        }
        if (k!=n) printf("\n");
    }
    return 0;
}
