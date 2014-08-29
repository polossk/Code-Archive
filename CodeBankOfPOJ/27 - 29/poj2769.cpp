#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
bool visit[1000005];
int main()
{
    int t, n, i, a[500], j, tmp;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        memset(visit, 0, sizeof(bool) * n); // 要多少初始多少
        bool ok;
        for (i = n; ; i++) // 从n开始
        {
            ok = 1;
            for (j = 0; j < n; j++)
            {
                tmp = a[j] % i;
                if (visit[tmp] == 0) visit[tmp] = 1;
                else
                {
                    ok = 0;
                    memset(visit, 0, sizeof(bool) * i); // 要多少初始多少
                    break;
                }
            }
            if (ok == 1) { printf("%d\n", i); break; }
        }
    }
    return 0;
}
