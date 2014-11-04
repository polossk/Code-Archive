#include <iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long x=1;
        for(int i=0;i<n;i++)
            x*=3;
        printf("%I64d\n",--x);
    }
}