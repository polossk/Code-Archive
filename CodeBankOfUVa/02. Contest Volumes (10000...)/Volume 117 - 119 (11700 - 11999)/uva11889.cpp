#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eps=1e-8;
const double pi=acos(-1.0);
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,c;
        scanf("%d%d",&a,&c);
        if(c%a!=0)
        {
            puts("NO SOLUTION");
            continue;
        }
        int ans=c/a;
        for(int i=c/a;i<=c;i+=c/a)
        {
            if(i/gcd(a,i)==c/a)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}