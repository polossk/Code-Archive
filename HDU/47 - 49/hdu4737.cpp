#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100010
using namespace std;
int a[maxn];
int l[maxn];
int f(int x,int y)
{
    int temp=a[x];
    for(int i=x+1;i<=y;i++)
    {
        temp|=a[i];
    }
    return temp;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int kase=1;kase<=T;kase++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(l,0,sizeof(l));
        long long ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int L,R;
        for(R=1;R<=n;R++)
        {
            L=R;
            while(L>=1&&f(L,R)<m) L--;//找最左边的下标值
            l[R]=++L;
        }
        for(int i=1;i<=n;i++)
        {
            //printf("l[%d]=%d\n",i,l[i]);
            if(l[i]) ans+=i-l[i]+1;
        }
        printf("Case #%d: %lld\n",kase,ans);
    }
    return 0;
}