#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int d[10005];
int t[10005];
int main()
{
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> d[i];
		memset(t, 0, sizeof(t));
		int ans = n;
		for (int i = 1; i <= n; ++i)
		{
			if (t[d[i]] == 1) continue;
			int start = i;
			int x = i; t[x] = 1;
			while (1)
			{
				x = d[x]; t[x] = 1;
				if (x == start) break;
			}
			ans--;
		}
		printf("%d\n", ans);
	}
	return 0;
}