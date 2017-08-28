/****
	*@author    Shen
	*@title     D
	*/

#include <cstdio>
using namespace std;

int n, m, k;
int index;
int data[105];

void solve()
{
    for (int i = 1; i <= n; i++)
        data[i] = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &index);
        if (!data[index])
            data[index] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &index);
        if (!data[index])
            data[index] = 2;
    }
    for (int i = 1; i < n; i++)
        printf("%d ", data[i]);
    printf("%d\n", data[n]);
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k))
        solve();
    return 0;
}
