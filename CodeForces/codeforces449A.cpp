/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :C
* @file         :G:\My Source Code\【ACM】比赛\0719 - CF\C.cpp
* @date         :2014/07/19 20:57
* @algorithm    :Greedy
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

typedef long long int64;

int64 n, m, k, ans;

int64 run()
{
    if (n - 1 + m - 1 < k) ans = -1;
	for (int64 i = 1; i <= n; i++)
    {
		int64 r = n / (n / i); i = r;
		if (k - (r - 1) > m - 1) continue;
		int64 o = max(k - (r - 1) + 1, 1LL);
		updateMax(ans, 1LL * (n / r) * (m / o));
	}
    return ans;
}

int main()
{
    cin >> n >> m >> k;
    cout << run() << endl;
    return 0;
}
