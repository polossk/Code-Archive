#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct pnt
{
	int value, len;
	inline bool operator<(const pnt& b) const { return len < b.len; }
};

const int MaxN = 9005;
int w, n, sum, an, pos;
pnt s[MaxN], ans[MaxN];

int getnum(int pos)
{
	int v = 0;
	for (int i = 0; i < n; i++)
	{
		if (v + s[i].len >= pos)
			return s[i].value;
		v += s[i].len;
	}
}

int cal(int pos)
{
	int num = getnum(pos), ans = 0;
	int r = (pos - 1) / w;
	int c = (pos - 1) % w;
	for (int i = r - 1; i <= r + 1; i++)
		for (int j = c - 1; j <= c + 1; j++)
	{
		int v = i * w + j;
		if (i < 0 || j < 0 || j >= w || v >= sum || v == pos - 1) continue;
		int num2 = getnum(v + 1);
		int t = abs(num2 - num);
		ans = max(ans, t);
	}
	return ans;
}

void solve()
{
	n = sum = an = 0; pos = 1;
	while (~scanf("%d%d", &s[n].value, &s[n].len) && s[n].value || s[n].len)
	{
		sum += s[n].len; n++;
	}
	s[n].len = s[n].value = 0;
	for (int k = 0; k <= n; k++)
	{
		int r = (pos - 1) / w;
		int c = (pos - 1) % w;
		for (int i = r - 1; i <= r + 1; i++)
			for (int j = c - 1; j <= c + 1; j++)
		{
			int v = i * w + j;
			if (i < 0 || j < 0 || j >= w || v >= sum) continue;
			ans[an].len = v + 1;
			ans[an++].value = cal(v + 1);
		}
		pos += s[k].len;
	}
	sort(ans, ans + an);
	pnt save = ans[0];
	printf("%d\n", w);
	for (int i = 0; i < an; i++)
	{
		if (ans[i].value == save.value) continue;
		printf("%d %d\n", save.value, ans[i].len - save.len);
		save = ans[i];
	}
	printf("%d %d\n", save.value, sum - save.len + 1);
	printf("0 0\n");
}

int main() {
	while (~scanf("%d", &w) && w) solve();
	printf("0\n");
	return 0;
}