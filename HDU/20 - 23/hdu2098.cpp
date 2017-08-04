#include <stdio.h>

int p[10001] = {0, 0, 1, 1, 0, 1};

int creat_prime(int prime[],int n,int total)
{
    register    int    i;
    register    int    j;
    register    int    gab=2;
    register    int    count;
    for(i=7;i<=n;i+=gab)
    {
        count=1;
        gab=6-gab;
        for(j=0;prime[j]*prime[j]<=i;j++)
        {
            if(i%prime[j]==0)
            {
                count=0;
                break;
            }
        }
        if(count)
        {
            prime[total]=i;
            p[i] = 1;
            total++;
        }
    }

    return total;
}

int main(void)
{
    int    prime[1229]={2,3,5};
    int    total=3;
    int    i;
    int    n=10001;

    total=creat_prime(prime,n,total);
    while (scanf("%d", &n), n)
    {
        total = 0;
        if (p[n - 2] && n - 2 != 2) total++;
        for (i = 3; i < n / 2; i++)
        {
            if (p[i] && p[n - i])
                total++;
        }
        printf("%d\n", total);
    }
}