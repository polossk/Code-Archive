//550
#include <cstdio>
int main()
{
    int x, y, z;
    int sum, mod, m, total;
    while (~scanf("%d %d %d", &x, &y, &z))
    {
        if(y != 0)
        {
            total = m = sum = 0;
            mod = y;
            while (sum != y)
            {
                sum = z * mod + m;
                m = sum / x;
                mod = sum % x;
                total++;
            }
            printf("%d\n",total);
        }
        else printf("1\n");
    }
    return 0;
}