/****
	*@author    Shen
	*@title     Î÷°²ÑûÇëÈüA
	*/

#include <cctype>
#include <cstdio>
using namespace std;

const int maxLen = (1 << 16);
char buffer[maxLen];
int len, res;

inline bool isDOGE(int i)
{
    return  (toupper(buffer[i]) == 'D') &&
            (toupper(buffer[i + 1]) == 'O') &&
            (toupper(buffer[i + 2]) == 'G') &&
            (toupper(buffer[i + 3]) == 'E');
}

void solve()
{
    char ch = 0;
    while (~scanf("%c", &ch)) buffer[len++] = ch;
    len -= 3;
    for (int i = 0; i < len; i++)
        if (isDOGE(i))
            res++;
    printf("%d\n", res);
}

int main()
{
    solve();
    return 0;
}
