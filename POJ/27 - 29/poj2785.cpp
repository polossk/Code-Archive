/****
	*@author    Shen
	*@title     poj 2785
	*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;

const int MaxN = 4005;
int64 A[MaxN], B[MaxN], C[MaxN], D[MaxN];
int64 Index[MaxN * MaxN];
int64 Search[MaxN * MaxN];

void solve(int n)
{
    for (int i = 0; i < n; i++)
        scanf("%I64d%I64d%I64d%I64d", &A[i], &B[i], &C[i], &D[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            Index[i * n + j] = A[i] + B[j];
            Search[i * n + j] = C[i] + D[j];
        }
    int n2 = n * n;
    int ans = 0;
    sort(Search, Search + n2);
    for (int i = 0; i < n2; i++)
        ans += upper_bound(Search, Search + n2, -Index[i])
            -lower_bound(Search, Search + n2, -Index[i]);
    printf("%d\n", ans);
}

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF) solve(n);
    return 0;
}
