#include<stdio.h>
#include<math.h>
#define eps 1e-8
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        int tmp=n*n-4*m;
        if(tmp>=0)
        {
            double x=sqrt((double)tmp);
            int y=x+eps;
            if(fabs(y-x)<=eps)
            {
                if((n&1 && y&1 )|| (!(n&1)&&!(y&1)))printf("Yes\n");
                else printf("No\n");
            }
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}