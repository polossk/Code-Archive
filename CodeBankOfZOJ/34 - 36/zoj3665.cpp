#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
long long solve(int r,long long sum)
{
    long long left=2,right=(long long)sqrt((double)sum);
    while(left<=right)
    {
        long long mid=(left+right)/2;
        double mm=(pow(1.0*mid,r+1)-mid)/(mid-1);
        if(mm>((double)sum+1e-2))
        {
            right=mid-1;
            continue;
        }
        long long temp=0;
        long long tt=1;
        for(int i=0;i<r;i++)
        {
            tt*=mid;
            temp+=tt;
        }
        if(temp==sum)return mid;
        else if(temp<sum)left=mid+1;
        else right=mid-1;
    }
    return 0;
}

int main()
{
    long long n;
    long long ans,ansk;
    int ansr;
    while(scanf("%lld",&n)!=EOF)
    {
        ans=n-1;
        ansr=1;
        ansk=n-1;
        for(int r=2;r<=40;r++)
        {
            long long temp=solve(r,n);
            //printf("%d\n",temp);
            if(temp==0)continue;
            if(r*temp<ans)
            {
                ans=r*temp;
                ansr=r;
                ansk=temp;
            }
            else if(r*temp==ans&&r<ansr)
            {
                ansr=r;
                ansk=temp;
            }
        }
        for(int r=2;r<=40;r++)
        {
            long long temp=solve(r,n-1);
            if(temp==0)continue;
            if(r*temp<ans)
            {
                ans=r*temp;
                ansr=r;
                ansk=temp;
            }
            else if(r*temp==ans&&r<ansr)
            {
                ansr=r;
                ansk=temp;
            }
        }
        printf("%d %lld\n",ansr,ansk);
    }
    return 0;
}