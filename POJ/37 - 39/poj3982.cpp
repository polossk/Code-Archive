#include <stdio.h>
#include <string.h>
int main()
{
    int a0,a1,a2;
    int b0[50],b1[50],b2[50],ans[50];
    int i,j,flag;
    while(scanf("%d%d%d",&a0,&a1,&a2)!=EOF)
    {
        memset(b0,0,sizeof(b0));
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        memset(ans,0,sizeof(ans));
        i = 49;
        while(a0>0)
        {
            b0[i] = a0%10;
            a0 /= 10;
            i--;
        }
        i = 49;
        while(a1>0)
        {
            b1[i] = a1%10;
            a1 /= 10;
            i--;
        }
        i = 49;
        while(a2>0)
        {
            b2[i] = a2%10;
            a2 /= 10;
            i--;
        }
        for(i=0;i<97;i++)
        {
            flag = 0;
            for(j=49;j>0;j--)
            {
                ans[j] = b0[j]+b1[j]+b2[j]+flag;
                flag = ans[j]/10;
                ans[j] = ans[j]%10;
            }
            if(flag>0)
            ans[j] = flag;
            for(j=49;j>0;j--)
            {
                b0[j] = b1[j];
                b1[j] = b2[j];
                b2[j] = ans[j];
            }
        }
        i = 0;
        while(!ans[i]) i++;
        for(;i<50;i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}