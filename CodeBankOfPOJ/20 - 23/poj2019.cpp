#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int val[255][255];
int mm[255];
int dpmin[255][255][8][8];//最小值
int dpmax[255][255][8][8];//最大值

void initRMQ(int n,int m)
{
    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m;j++)
		dpmin[i][j][0][0] = dpmax[i][j][0][0] = val[i][j];
    for (int ii = 0; ii <= mm[n]; ii++)
	for (int jj = 0; jj <= mm[m]; jj++)
		if(ii+jj)
			for (int i = 1; i + (1<<ii) - 1 <= n; i++)
			for (int j = 1; j + (1<<jj) - 1 <= m; j++)
            {
				if(ii)
				{
					dpmin[i][j][ii][jj] = min(dpmin[i][j][ii-1][jj], dpmin[i+(1<<(ii-1))][j][ii-1][jj]);
					dpmax[i][j][ii][jj] = max(dpmax[i][j][ii-1][jj], dpmax[i+(1<<(ii-1))][j][ii-1][jj]);
				}
				else
				{
					dpmin[i][j][ii][jj] = min(dpmin[i][j][ii][jj-1],dpmin[i][j+(1<<(jj-1))][ii][jj-1]);
					dpmax[i][j][ii][jj] = max(dpmax[i][j][ii][jj-1],dpmax[i][j+(1<<(jj-1))][ii][jj-1]);
				}
			}
}
//查询矩形的最大值
int rmq1(int x1, int y1, int x2, int y2)
{
    int k1 = mm[x2 - x1 + 1];
    int k2 = mm[y2 - y1 + 1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max(max(dpmax[x1][y1][k1][k2], dpmax[x1][y2][k1][k2]), max(dpmax[x2][y1][k1][k2], dpmax[x2][y2][k1][k2]));
}
//查询矩形的最小值
int rmq2(int x1, int y1, int x2, int y2)
{
    int k1 = mm[x2 - x1 + 1];
    int k2 = mm[y2 - y1 + 1];
    x2 = x2 - (1 << k1) + 1;
    y2 = y2 - (1 << k2) + 1;
    return min(min(dpmin[x1][y1][k1][k2], dpmin[x1][y2][k1][k2]), min(dpmin[x2][y1][k1][k2], dpmin[x2][y2][k1][k2]));
}

int main()
{
    mm[0] = -1;
    for (int i = 1; i <= 500; i++)
        mm[i] = ((i & (i - 1)) == 0)? mm[i - 1] + 1: mm[i - 1];
    int N,B,K;
    while (scanf("%d%d%d",&N,&B,&K) == 3)
    {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &val[i][j]);
        initRMQ(N, N);
        int x, y;
        while (K--)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", rmq1(x, y, x + B - 1, y + B - 1) - rmq2(x, y, x + B - 1, y + B - 1));
        }
    }
    return 0;
}
