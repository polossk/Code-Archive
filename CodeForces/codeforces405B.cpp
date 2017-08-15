/****
	*@author PoloShen
	*Title:
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

char s[5005];
int n;
void solve()
{
int ans=0,flag=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='L'&&flag!=1)
        {
            sum=0;
            continue;
        }
        if(s[i]=='L'&&flag==1)
        {
            flag=0;
            ans+=sum;
            sum=0;
            continue;
        }
        if(s[i]=='R')
        {
            flag=1;
            int j=i;
            while(i<=n&&(s[i]=='.'||s[i]=='R'))
                i++;
            if(i<=n&&(i-j)%2==0&&s[i]=='L')
                ans++;
            continue;
        }
        sum++;
    }
    ans+=sum;
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    solve();
    return 0;
}
