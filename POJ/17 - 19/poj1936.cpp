#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MaxN = 100005;
char a[MaxN], b[MaxN];
int main()
{
    while (~scanf("%s%s", a, b))
    {
        char *p, *q;
        for (p = a, q = b; *p != 0; p++, q++)
        {
            while (*p != *q && *q != '\0') q++;
            if (*q == 0) break;
        }
        if (*p != 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}