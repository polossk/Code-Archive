#include <stdio.h>

int Sum(int n, int as)
{
    int sum = 0;
    while (n)
    {
        sum += n % as;
        n /= as;
    }
    return sum;
}

int main(void)
{
    int n;

    while (scanf("%d", &n), n)
        printf(Sum(n,10)==Sum(n,12)&&Sum(n,10)==Sum(n,16)?"%d is a Sky Number.\n":"%d is not a Sky Number.\n", n);

    return 0;
}
