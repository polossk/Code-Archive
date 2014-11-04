#include <math.h>
#include <stdio.h>
#define S(x) (((int)x)*((int)x))
int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", S(sqrt((double)n)) == n);

    return 0;
}
