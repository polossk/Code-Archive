#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

bitset<500*10*500*10+10>de;

int tr(int i,int j,int k,int l)
{
    return (i-1)*10*500*10+j*500*10+(k-1)*10+l;
}

unsigned short dt[501][10][501][10];

int fc[510],n;
void upd(int i,int j,int k,int l,int i2,int j2,int k2,int l2,int i3,int j3,int k3,int l3)
{
    if(de[tr(i2,j2,k2,l2)]==de[tr(i3,j3,k3,l3)])
    {
        de[tr(i,j,k,l)]=de[tr(i2,j2,k2,l2)];
        if(dt[i2][j2][k2][l2]>dt[i3][j3][k3][l3])
            dt[i][j][k][l]=dt[i2][j2][k2][l2];
        else dt[i][j][k][l]=dt[i3][j3][k3][l3];
    }
    else if(de[tr(i2,j2,k2,l2)]>de[tr(i3,j3,k3,l3)])
    {
        dt[i][j][k][l]=dt[i2][j2][k2][l2];
        de[tr(i,j,k,l)]=de[tr(i2,j2,k2,l2)];
    }
    else
    {
        dt[i][j][k][l]=dt[i3][j3][k3][l3];
        de[tr(i,j,k,l)]=de[tr(i3,j3,k3,l3)];
    }
}
void build()
{
    for(int j=0; (1<<j)<=n; ++j)
        for(int i=1; i+(1<<j)-1<=n; ++i)
            for(int l=0; (1<<l)<=n; ++l)
                for(int k=1; k+(1<<l)-1<=n; ++k)
                {
                    if(!l&&j)upd(i,j,k,l,i,j-1,k,l,i+(1<<(j-1)),j-1,k,l);
                    if(l)upd(i,j,k,l,i,j,k,l-1,i,j,k+(1<<(l-1)),l-1);
                }
    fc[1]=0;
    for (int i=2;i<=n;++i)fc[i]=fc[i-1]+((1<<(fc[i-1]+1))<=i);
}

int ty(int i,int j,int k,int l)
{
    return (int(de[tr(i,j,k,l)])<<16)+dt[i][j][k][l];
}

int q1d(int i,int j,int c,int d)
{
    return max(ty(i,j,c,fc[d-c+1]),ty(i,j,d-(1<<fc[d-c+1])+1,fc[d-c+1]));
}

int q2d(int a,int b,int c,int d)
{
    return max(q1d(a,fc[b-a+1],c,d),q1d(b-(1<<fc[b-a+1])+1,fc[b-a+1],c,d));
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++)
    {
        de.reset();
        int q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            int t;
            scanf("%d",&t);
            de[tr(i,0,j,0)]=(t>>16);
            dt[i][0][j][0]=(t&((1<<16)-1));
        }
        build();
        printf("Case %d:\n",kase);
        for(int i=1;i<=q;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            printf("%d\n",q2d(a,a+c-1,b,b+c-1));
        }
    }
    return 0;
}
