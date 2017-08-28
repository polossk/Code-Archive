#include<stdio.h>
int main(){
    int n,num,i;
    int a[100],b[100],flag;
    scanf("%d",&n);
    while(n--){
        flag=0;
        scanf("%d",&num);
        for(i=0; i<num; ++i)
            scanf("%d",&a[i]);
        for(i=0; i<num; ++i)
            scanf("%d",&b[i]);
        for(i=0; i<num; ++i){
            if(a[i]!=b[i]||a[i]!=b[num-i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("both\n");
            continue;
        }
        flag=0;
        for(i=0; i<num; ++i){
            if(a[i]!=b[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("queue\n");
            continue;
        }
        flag=0;
        for(i=0; i<num; ++i){
            if(a[i]!=b[num-i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("stack\n");
            continue;
        }
        printf("neither\n");
    }
}