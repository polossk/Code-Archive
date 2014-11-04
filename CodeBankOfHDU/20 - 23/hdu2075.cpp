#include<stdio.h>

int main(void)
{
    int n, a, b;

    scanf("%d", &n);
    while(n-- && scanf("%d%d", &a, &b))
        puts(a % b ? "NO" : "YES");

    return 0;
}

