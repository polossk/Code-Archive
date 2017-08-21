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
const int Max=100010;
const int INF=1000000007;

int a[103];
int num[103];
int rem[Max];
bool ans[Max];
int n,cap;
int main()
{
    int t;
    //cout<<pow(6,4)-1<<endl;
    scanf("%d",&t);int kk=1;
    while(t--)
    {
        memset(ans,0,sizeof ans);
        scanf("%d%d",&n,&cap);
        for(int i=0; i<n; i++)
            scanf("%d",a+i);
        for(int i=0; i<n; i++)
            scanf("%d",num+i);
        ans[0]=1;
        for(int i=0; i<n; i++)
        {
            memset(rem,0,sizeof rem);
            for(int j=0; j<=cap; j++)
            {
                if(j+a[i]>cap||rem[j]>=num[i])
                    continue;
                if(ans[j])
                {
                    if(ans[j+a[i]])
                    {
                        rem[j+a[i]]=min(rem[j+a[i]],rem[j]+1);
                        continue;
                    }
                    ans[j+a[i]]=1;
                    rem[j+a[i]]=rem[j]+1;
                }
            }
        }
        int out=0;
        for(int i=1; i<=cap; i++)
            if(ans[i])
                out++;
        printf("Case %d: %d\n",kk++,out);
    }
    return 0;
}
/*
4 100000
1 12 456 5678
5 5 5 5
*/
