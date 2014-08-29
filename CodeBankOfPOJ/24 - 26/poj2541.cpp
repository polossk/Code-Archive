#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

int n, l;
char s[1002000];
int last[13][9000];
int main()
{
	while (~scanf("%d%d", &n, &l))
	{
		scanf("%s", s);
		memset(last, -1, sizeof(last));
		for (int i = 0, sz = n + l - 1; i < sz; i++)
		{
			int now = 0, temp = 1;
			if (i >= n - 1) s[i + 1] = '0';
			for (int j = 0; j < 13 && i - j >= 0; j++)
			{
				int x = s[i - j] - '0';
				if (x) now += temp;
				temp <<= 1;
				if (i >= n - 1 && last[j][now] != -1) s[i + 1] = s[last[j][now] + 1];
				last[j][now]=i;
			}
		}
		s[n + l] = '\0';
		printf("%s\n", s + n);
	}
	return 0;
}
