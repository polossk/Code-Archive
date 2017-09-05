/****
	*@author    Shen
	*@title     B - BNUOJ 29120
	*/

//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize ("O2")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

typedef long long int64;
int a[1005];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        int x,ans;
        for(int i=1;i<=n+1;i++)
        {
            scanf("%d",&x);
            if(a[x]==1)
                {
                    ans=x;
                }
            a[x]=1;
        }
        printf("%d\n",ans);
    }
}
