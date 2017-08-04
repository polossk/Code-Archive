/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int k,m,n,i,j,sum,min;
    char str[100000];
    while(scanf("%d%*c",&n) && n){
        sum=0;
        for(i=0; i<n; i++){
            gets(str);
            m=strlen(str);
            k=0;
            for(j=0; j<m; j++){
                if(str[j]==' ')
                    k++;
            }
            if(i==0)
                min=k;
            else{
                if(min>k)
                    min=k;
            }
            sum+=k;
        }
        printf("%d\n",sum-min*n);
    }
    return 0;
}
