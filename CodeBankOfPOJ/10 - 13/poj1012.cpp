/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][2] A
#       @file         :G:\My Source Code\【ACM】训练\0711 - [NWPU][SRM][2]\A.cpp
#       @date         :2014-07-11 19:23
#       @algorithm    :Joseph Loop
******************************************************************************/

#include <cstdio>
#include <cstring>
using namespace std;

int tmp[15], data[15];

void solve()
{
	for (int k = 1; k < 14; k++)
	{
		int res = 1;
		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= k; i++)
        {
            tmp[i] = (tmp[i - 1] + res - 1) % (2 * k - i + 1);
            if (tmp[i] < k) i = 0, res++;
        }
		data[k] = res;
	}
}

int main ()
{
	int k; solve();
	while (~scanf("%d", &k) && k)
		printf("%d\n", data[k]);
	return 0;
}
