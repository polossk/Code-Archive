// <!--encoding UTF-8 UTF-8编码--!>
/*****************************************************************************
*----Stay Hungry Stay Foolish----
*@author    :   Shen
*@name      :   E
******************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int64;
const int MaxL = 2000005;
const int64 MD = 100000LL;
int n;
char data[MaxL], line[MaxL];
#define update if (isdoge == 0 && ans > MD) isdoge = 1;

void solve()
{
    getchar();                  // 消除空格
    bool isdoge = 0;            // 是否输出doge
    int64 ans = 1LL;            // 答案
    int64 nu$ = 0LL, nu_ = 0LL; // 空格数量，竖线数量
    int l = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        gets(line); l = strlen(line);
        copy(line, line + l, data + len);
        len += l;
    }
    for (int i = 0; i < len; i++)
    {
        if (data[i] == '{')
        {
            nu_ = 0LL; i++;
            while (data[i] != '}') { if (data[i] == '|') nu_++; i++; }
            ans *= nu_ + 1; update;
        }
        else if (data[i] == '$')
        {
            nu$ = 0LL; i++;
            for ( ; data[i] != '$'; i++)
                if (data[i] == ' ') nu$++;
                else { ans *= nu$ + 1; nu$ = 0; update; }
            ans *= nu$ + 1; update;
        }
    }
    if (isdoge) puts("doge");
    else printf("%I64d\n", ans);
}

int main()
{
    while (~scanf("%d", &n)) solve();
    return 0;
}
