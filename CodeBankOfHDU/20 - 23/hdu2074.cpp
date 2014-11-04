#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char a[81][81];

void eva(int x, char c)
{ 
        int     i = x;
        int     j = x;
        if(2*x>n) a[i][j]=c;
        else
        {
                for(;j<=n-x;j++) a[i][j]=c;
                for(;i<=n-x;i++) a[i][j]=c;
                for(;j>x;j--) a[i][j]=c;
                for(;i>x;i--) a[i][j]=c;
        }
} 

int main(void)
{
    int i, j, t = 0;
    char c[2][2];
    
    while (scanf("%d%s%s", &n, c, c+1) != EOF)
    {
        if (t++) putchar('\n');
        if (n == 1)
        {
            printf("%c\n", c[0][0]);
            continue;
        }
        memset(a, 0, sizeof(a));
        if (!(n/2%2)) swap(c[0][0], c[1][0]);
        for (i=1; i<=n/2+n%2; eva(i, c[i&1][0]), i++);
        a[1][1] = ' ';a[1][n] = ' ';
        a[n][1] = ' ';a[n][n] = ' ';
        for(i=1;i<=n;i++)
        {
            for(j=1;a[i][j];j++)
                putchar(a[i][j]);
            putchar('\n');
        }        
    }
    return 0;
}
