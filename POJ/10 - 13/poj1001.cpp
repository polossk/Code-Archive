#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int MaxL = 1000;
int n, point, index; // n次幂。point代表小数点后有几位。
int si[MaxL], res[MaxL], tmp[MaxL], l; // si[MaxL]存s变成的整数，一位一位存
string s;
void _toInt() // 让s变成一个整数串，并且记录下小数点后有几位
{ 
	point = 0;  // 初始化point;
	index = 0;  // si的下标变量
	int l = s.length();
	int i = l - 1, flag = 0;
	for (int j = 0; j <= i; j++)
	{
		if (s[j] == '0' && !index && !flag)
		/*除去前导0，前导0满足3个要求 1.为0  2.在.前面 3.在数前面*/
			continue;
		if (s[j]=='.')
		{
			for (i = l - 1; s[i] == '0'; i--); // 除去后导0
			flag = 1;
			continue;
		}
		if (flag) { si[index++] = s[j] - 48; point++; }
		else si[index++] = s[j] - 48;
	}
}
void print()
{
	int k = point * n;
	if (l + 1 > k)
	{
		for (int i = 1; i <= l + 1; i++)
		{
			if (i == l + 1 - k + 1) cout << ".";
			cout << res[i - 1];
		}
	}
	else{
		cout << ".";
		for (int i = 0; i < k - l - 1; i++)
			cout << "0";
		for (int i = 0; i <= l; i++)
			cout << res[i];
	}
	cout << endl;
}
int main()
{
	while (cin >> s >> n)
	{
		_toInt();
		memcpy(res, si, sizeof(res));
		l = index - 1; // 记录res的长度
		int tsz; // 记录中间过程的下标
		for (int tt = 0; tt < n - 1; tt++) // 进行n - 1次迭代
		{
			memset(tmp, 0, sizeof(tmp)); // 把中间变量置为0
			for (int i = index - 1; i >= 0; i--) // 对于si的每一位
			{
				tsz = index - i - 2; // 要把这位的结果从这里开始放。模拟竖式乘法
				for (int j = l; j >= 0; j--) // 乘以res中的每一位
				{
					tsz++;
					tmp[tsz] += si[i] * res[j];
					if (tmp[tsz] >= 10)
					{
						int k = tmp[tsz] / 10;
						tmp[tsz] %= 10;
						tmp[tsz + 1] += k;
					}
				}
			}
			tsz++;
			while (tmp[tsz] != 0)
			{
				if (tmp[tsz] >= 10)
				{
					int k = tmp[tsz] / 10;
					tmp[tsz] %= 10;
					tmp[tsz + 1] += k;
				}
				tsz++;
			}
			tsz--;
			if (tsz > l) l = tsz;
			for (int i = 0; i <= l; i++) res[i] = tmp[l - i];
		}
	print();
	}
	return 0;
}