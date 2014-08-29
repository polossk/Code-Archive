#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MaxN = 100010;

int n, top, ans, num[4], dp[MaxN], s[MaxN];

int main()
{
    
    int i, j, begin, mid, end;
    scanf("%d", &n);
    dp[1] = 1, top = 2;
    while (top <= n)
        dp[top++] = ((dp[top - 1] << 1) + 1) % 1000000;
    ans = 0;
    for (i = 1; i <= 3; i++)
        scanf("%d", &num[i]);
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= num[i]; j++)
        {
            int si; scanf("%d", &si);
            s[si] = i;
        }
    }
    i = n;
    begin = end = s[i];
    while (i >= 1)
    {
        if (begin != end)
        {
            ans = (ans + 1 + dp[i - 1]) % 1000000;
            end = mid;
        }
        begin = s[--i], mid = 6 - begin - end;
    }
    printf("%d\n%d\n", s[n], ans);
    return 0;
}