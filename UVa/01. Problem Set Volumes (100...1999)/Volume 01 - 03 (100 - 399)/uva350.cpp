#include <iostream>
using namespace std;
int table[1000000];
int main()
{
	int z, i, m, tt = 0;
	while (cin >> z >> i >> m >> table[0])
	{
		if (!z && !i && !m && !table[0]) break;
		int t = 0, flag = 0;
		int f = 0;
		while (flag == 0)
		{
			t++;
			table[t] = (table[t-1] * z + i) % m;
			for (int j = 0; j < t; j++)
			{
				if (table[j] == table[t])
				{
					f = j;
					flag = 1;
					break;
				}
			}
		}
		cout << "Case " << ++tt << ": " << t - f << endl;
	}
	return 0;
}