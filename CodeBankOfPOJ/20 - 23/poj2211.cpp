#include <iostream>
#include <cstdio>
using namespace std;
int a[2005];
int main()
{
	int n, top, tot, t, tt;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> top >> tot; t = 0;
		for (int j = 0; j < tot; j++) cin >> a[j];
		for (int j = 0; j < tot; j++)
		{
			tt = a[j] - 1;
			for (int k = top - j - 1; k >= top - tot + 1; k--) tt *= k;
			t += tt;
			for (int k =j + 1; k < tot; k++) if (a[k] > a[j]) a[k]--;
		}
		printf("Variace cislo %d ma poradove cislo %d.\n", i + 1, t + 1);
	}
}
