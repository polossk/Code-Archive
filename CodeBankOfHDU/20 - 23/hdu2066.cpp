#include <stdio.h>
#define Max 99999
int mp[1001][1001];
int main(void)
{
    int i, j, k;
    int x, y, cost;
    int len, min;
    int T, S, D;
    int visit[1024];

    while (scanf("%d%d%d", &T, &S, &D) != EOF)
    {
        for (i = 0; i < 1001; i++)
        {
            for (j = 0; j < 1001; j++)
                mp[i][j] = Max;
        }

        len = 0;

        for (i = 0; i < T; i++)
        {
            scanf("%d%d%d", &x, &y, &cost);
            if (mp[x][y] > cost) mp[x][y] = mp[y][x] = cost;
            if (len < x) len = x;
            if (len < y) len = y;
        }

        for (i = 0; i < S; i++)
        {
            scanf("%d", &x);
            mp[0][x] = 0;
        }

        for (i = 0; i <= len; visit[i++] = false);

        for (i = 1; i <= len; i++)
        {
            min = Max;
            for (j = 1; j <= len; j++)
            {
                if (!visit[j] && min > mp[0][j])
                {
                    min = mp[0][j];
                    k = j;
                }
            }
            if (min == Max) break;
            visit[k] = true;
            for (j = 1; j <= len; j++)
            {
                if (!visit[j] && mp[0][j] > mp[0][k] + mp[k][j])
                    mp[0][j] = mp[0][k] + mp[k][j];
            }
        }

        min = Max;
        for (i = 0; i < D; i++)
        {
            scanf("%d", &x);
            if (min > mp[0][x])
                min = mp[0][x];
        }
        printf("%d\n", min);
    }

    return 0;
}
