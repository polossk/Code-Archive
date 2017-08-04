#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }

int n, m;
char map[101][11];
int s[101][1024];
int num[101], v[1024];
int maxx;

int ok(int s, int t)
{
    for (int i = 0, j = 0; i < m; )
	{
        j = t & (1  <<  i);
        if (j)
		{
            if (map[s][i + 1] == 'H') return 0;
            if (i + 1 < m && (t & (1  <<  (i + 1)))) return 0;
            if (i + 2 < m && (t & (1  <<  (i + 2)))) return 0;
            i += 3;
        }
        else i++;
    }
    return 1;
}

void init(){
    for (int i = 1; i <= n; i++) for (int j = 0; j < maxx; j++)
        if (ok (i, j))
	{
        s[i][num[i]] = j;
        num[i]++;
    }
    for (int i = 0; i < maxx; i++) for (int j = 0; j < m; j++)
		if (i & (1  <<  j)) v[i]++;
}

int ok2(int s, int t)
{
    for (int i = 0, j = 0, k = 0; i < m; i++)
	{
        j = s & (1  <<  i);
        k = t & (1  <<  i);
        if (j && k) return 0;
    }
    return 1;
}

int dp[101][1024][1024];

void solve (){
    int i, j, k, t;
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        cin >> map[i][j];
    maxx = pow(2.0, m);
    init();
    if (n == 1)
	{
		int ans = 0;
        for (int i = 0; i < num[1]; i++)
            ans = max(ans, v[s[1][i]]);
        cout << ans << endl;
        return;
	}
    for (int i = 0; i < num[1]; i++) for (int j = 0; j < num[2]; j++)
        if (ok2(s[1][i], s[2][j]))
            dp[2][j][i] = v[s[1][i]] + v[s[2][j]];
    for (int i = 3; i <= n; i++) for (int j = 0; j < num[i]; j++)
        for (int k = 0; k < num[i - 1]; k++)
            if (ok2(s[i][j], s[i - 1][k]))
	{
        for (int t = 0; t < num[i - 2]; t++)
            if (ok2(s[i][j], s[i - 2][t]) && ok2(s[i - 1][k], s[i - 2][t]))
                updateMax(dp[i][j][k], dp[i - 1][k][t] + v[s[i][j]]);
    }
    int ans = 0;
    for (int i = 0; i < num[n]; i++)
        for (int j = 0; j < num[n - 1]; j++)
            updateMax(ans, dp[n][i][j]);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}