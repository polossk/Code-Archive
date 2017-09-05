#include <stdio.h>

int main(void)
{
    int    t[5600];
    int    n, i, j, c;

    scanf("%d",&c);
    while (c--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
                scanf("%d",&t[(i+1)*(i+2)/2+j-1]);
        for(i=n-2;i>=0;i--)
            for(j=0;j<=i;j++)
                t[(i+1)*(i+2)/2+j-1]+=t[(i+3)*(i+2)/2+j-1]>t[(i+3)*(i+2)/2+j]?t[(i+3)*(i+2)/2+j-1]:t[(i+3)*(i+2)/2+j];
        printf("%d\n",t[0]);
    }
    return 0;
}
