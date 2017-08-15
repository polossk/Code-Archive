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
const double pi=acos(-1.0);
typedef long long LL;
const int Max=2010;
const int INF=1000000007 ;


int parent[Max];
LL count1[Max];
int num[Max];
int getparent(int t)
{
    if(t==parent[t])
        return t;
    return parent[t]=getparent(parent[t]);
}
struct point
{
    int u,v;
    LL value;
} points[Max*Max];
int p=0;
struct cao
{
    char num[11][11];
} caos[Max];
bool operator<(const point& a,const point& b)
{
    return a.value<b.value;
}
int n,m,k,w;
int com(int i,int j)
{
    int ans=0;
    for(int k=0; k<n; k++)
        for(int h=0; h<m; h++)
            if(caos[i].num[k][h]!=caos[j].num[k][h])
                ans++;
    return ans;
}
vector<int> vec[Max];
bool rem[2010];
vector<pair<int,int> > ps;
LL all=0;
void dfs(int t,int before)
{
    if(rem[t])
        return ;
    rem[t]=1;
    int tool=com(t,before)*w;
    if(before!=0&&tool>n*m)
    {
        all+=tool-n*m;
         ps.push_back(pair<int,int>(t,0));
    }
    else
       ps.push_back(pair<int,int>(t,before));
    for(int i=0; i<vec[t].size(); i++)
    {
        dfs(vec[t][i],t);
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int i=1; i<=k; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%s",caos[i].num[j]);
    }
    for(int i=1; i<=k; i++)
        parent[i]=i;
    for(int i=1; i<k; i++)
        for(int j=i+1; j<=k; j++)
        {
            points[p].u=i;
            points[p].v=j;
            points[p++].value=com(i,j)*w;
        }
    sort(points,points+p);
    int tool=0;
    LL ans=n*m;
    for(int i=0; i<p; i++)
    {
        if(tool==k-1)
            break;
        int p1=getparent(points[i].u);
        int p2=getparent(points[i].v);
        if(p1==p2)
            continue;
        vec[points[i].v].push_back(points[i].u);
        vec[points[i].u].push_back(points[i].v);
        tool++;
        ans+=points[i].value;
        parent[p1]=parent[p2];
    }
    dfs(1,0);
    cout<<ans-all<<endl;
    for(int i=0;i<k;i++)
        cout<<ps[i].first<<" "<<ps[i].second<<endl;
    return 0;
}
