#include <iostream>
#include <cstdio>
using namespace std;
{
    double c[3001],s[3001],x,y;
    int n,i,t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        scanf("%lf%lf",&x,&y);
        for (i=1; i<=n; i++)
            scanf("%lf",&c[i]);
        s[1]=c[1];
        s[0]=s[1];
        for (i=2; i<=n; i++)
        {
            s[i]=s[i-1]+c[i];
            s[0]+=s[i];
        }
        printf("%.2lf\n",(n*x+y-2*s[0])/(n+1));
        if (t) printf("\n");
    }
}

