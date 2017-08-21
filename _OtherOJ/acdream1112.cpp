/******************************************************
* author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
//freopen ("in.txt" , "r" , stdin);
using namespace std;

#define eps 1e-8
#define zero(_) (abs(_)<=eps)
const double pi=acos(-1.0);
typedef long long LL;
const int Max=5000010;
const int INF=1000000007;

int f[300];
bool rem[Max];
int out[Max];
int least[Max];
int p=0;
void init()
{
    for(int i=2; i<Max; i++)
        if(!rem[i])
        {
            for(int j=i*2; j<Max; j+=i)
            {
                if(least[j]==-1)
                    least[j]=i;
                rem[j]=1;
            }
            least[i]=i;
        }
}
int getans(int t)
{
    if(f[t]!=-1)
        return f[t];
    int Rem[1000];
    memset(Rem,0,sizeof Rem);
    Rem[0]=1;
    for(int i=1; i<=t/2; i++)
    {
        Rem[getans(i)]=1;
        Rem[getans(t-i)]=1;
        Rem[getans(t-i)^getans(i)]=1;
    }
    int to=0;
    while(Rem[to])to++;
    return f[t]=to;
}
int F(int n)
{
    if(out[n]!=-1)
        return out[n];
    int ans=F(n/least[n])+1;
    return out[n]=ans;
}
int main()
{
    int n;
    memset(f,-1,sizeof f);
    memset(out,-1,sizeof out);
    memset(least,-1,sizeof least);
    f[1]=1;
    init();
    out[1]=0;
    for(int i=0; i<20; i++)
        F(1<<i);// cout<<i<<" "<<getans(i)<<endl;
    while(scanf("%d",&n)==1)
    {
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int t;
            scanf("%d",&t);
            ans^=getans(F(t));
        }
        if(ans)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
