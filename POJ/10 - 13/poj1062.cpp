#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int M,N,dengji[110];
int dis[110],map[110][110];
bool vis[110];

void dijkstra(int m,int n)
{
    int i,k,num=1;
    int min;
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    vis[0]=1;
    for(i=0;i<=N;i++)
        if( dengji[i]>=m && dengji[i]<=n)
            dis[i]=map[0][i];
        k=0;
        while(1)
        {
            min=99999999;
            for(i=0;i<=N;i++)
                if(dengji[i]>=m && dengji[i]<=n && !vis[i] && min>dis[i])
                {
                    min=dis[i];
                    k=i;
                }
                vis[k]=1;
                if(k==1)
                    return;
            for(i=0;i<=N;i++)
                if( dengji[i]>=m && dengji[i]<=n && !vis[i] && dis[i]>dis[k]+map[k][i])
                {
                    dis[i]=dis[k]+map[k][i];
                }
        }
}

int main()
{
    int i,j,k,t,p;
    memset(map,127,sizeof(map));
    cin>>M>>N;
    int ans=999999999;
    for(i=1;i<=N;i++)
    {
        scanf("%d%d%d",&map[0][i],&dengji[i],&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d%d",&t,&p);
            map[t][i]=p;
        }
    }
    for( i=dengji[1]-M; i<=dengji[1]; i++)
    {
        dijkstra(i,i+M);
        if(ans>dis[1])
            ans=dis[1];
    }
    cout<<ans<<endl;
    return 0;
}