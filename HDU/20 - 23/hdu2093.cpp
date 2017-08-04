#include <cstdio>
#include <cstdlib>
#include <cstring>
#define    MAX 1000

typedef struct
{
    char    name[11];
    int    sum;
    int    total;
}credit;

int cmp(const void *a, const void *b)
{
    if ((*(credit *)a).total != (*(credit *)b).total)
        return (*(credit *)a).total - (*(credit *)b).total;
    else if ((*(credit *)b).sum != (*(credit *)a).sum)
        return (*(credit *)b).sum - (*(credit *)a).sum;
    else
        return strcmp((*(credit *)b).name, (*(credit *)a).name);
}

int main(void)
{
    int    res, t, f;
    int    i, n, m, j;
    char    style[10];
    credit    c[MAX] = {0};

    scanf("%d%d", &n, &m);
    for (i = 0; scanf("%s", c[i].name) != EOF; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%s", style);
            res = sscanf(style, "%d(%d)", &t, &f);
            if (res == 2)
            {
                c[i].total++;
                c[i].sum += t + f * m;
            }
            else if (res == 1 && t > 0)
            {
                c[i].total++;
                c[i].sum += t;
            }
        }
    }

    qsort(c, i, sizeof(credit), cmp);
    for (i--; i >= 0; i--)
        printf("%-10s %2d %4d\n", c[i].name, c[i].total, c[i].sum);

    return 0;
}
