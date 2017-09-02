#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,j;
    int flag;
    int number[1005],many;
    int a[10005];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",number+i,&many);
        for(j=0;j<many;j++)scanf("%d",a+j);
        printf("%d %d\n",number[i],(many+1)/2);
        for(j=0,flag=1;j<many;j+=2,flag++){
            if(j==0)printf("%d",a[0]);
            else{
                sort(a,a+j+1);
                printf(flag%10==1?"%d":" %d",a[j/2]);
                if(flag%10==0)printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
