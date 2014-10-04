/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] C
#       @file         :C.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :Counting
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 m, n;
int64 exp_10[20] = { 1 };

void init()
{
    for (int i = 1; i < 20; i++)
		exp_10[i] = exp_10[i - 1] * 10;
}

int64 calc(int64 b)
{
	if (b < 0) return 0;

	char s[20]; sprintf(s, "%lld", b);
	int n = strlen(s);

	int64 suf[20]; suf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] + (s[i] - '0') * exp_10[n - i - 1];

	int64 res = 1, pref = 0;
	for (int i = 1; i < n; i++)
    {
		pref = pref * 10 + (s[i - 1] - '0');
		if (s[i] != '0') // 第二位是否为零
			res += pref * exp_10[n - i - 1];
		else
			res += (pref - 1) * exp_10[n - i - 1] + suf[i + 1] + 1;
	}
	return res;
}

int main()
{
	init();
	while (cin >> m >> n && m != -1 && n != -1)
        cout << calc(max(m, n)) - calc(min(m, n) - 1) << endl;
}
