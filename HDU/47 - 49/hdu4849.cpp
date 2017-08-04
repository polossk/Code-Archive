/****
	*@author    Shen
	*@title     Î÷°²ÑûÇëÈüC
	*/

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long int64;

const int maxN = 1005;
const int maxM = 1000005;
const int64 xmod = 5837501;
const int64 ymod = 9860381;
const int64 zmod = 8475871;

int n, m, n2;
int x0, x1, y0, y1;
int64 x[maxM], y[maxM], z[maxM], c[maxN][maxN];
int64 dis[maxN];
bool inqueue[maxN];

inline int64 calcx(int k)
{
    return (12345 + x[k - 1] * 23456 + x[k - 2] * 34567
        + x[k - 1] * x[k - 2] * 45678) % xmod;
}

inline int64 calcy(int k)
{
    return (56789 + y[k - 1] * 67890 + y[k - 2] * 78901
        + y[k - 1] * y[k - 2] * 89012) % ymod;
}

void SPFA()
{
    for (int i = 0; i < n; i++)
        dis[i] = 1LL << 62;
    dis[0] = 0;
    for (int i = 0; i < n; i++)
		inqueue[i] = false;
    inqueue[0] = true;
    queue<int64> q; q.push(0);
    while (!q.empty())
    {
        int i = q.front(); q.pop();
        inqueue[i] = false;
        for (int j = 0; j < n; j++)
            if (dis[j] > dis[i] + c[i][j])
            {
                dis[j] = dis[i] + c[i][j];
                if (!inqueue[j])
				{
                    inqueue[j] = true;
                    q.push(j);
                }
            }
    }
}

int64 solve()
{
    x[0] = x0; x[1] = x1;
    y[0] = y0; y[1] = y1;
    for (int k = 2; k < n * n; k++)
        x[k] = calcx(k), y[k] = calcy(k);
    for ( int k = 0; k < n * n; k++)
        z[k] = (x[k] * 90123 + y[k]) % zmod + 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                c[i][j] = z[i * n + j];
            else
                c[i][j] = 0;
    SPFA();
    for (int i = 0; i < n; i++)
        dis[i] %= m;
    sort(dis + 1, dis + n);
    cout << dis[1] << endl;
}

int main(){
    while ( cin >> n >> m >> x0 >> x1 >> y0 >> y1 )
        solve();
    return 0;
}
