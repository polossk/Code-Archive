/****
	*COPYRIGHT NOTICE 
    *Copyright (c) 2014 
    *All rights reserved
    
	*@author    Shen
	*@name		D
	*@file		G:\My Source Code\比赛与日常练习\0608 - wuyiqi退役赛\D\D.cpp
	*@date		2014/6/8 18:06
	*/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

/*//STL
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>
*/

/*//Computational Geometry
#include <complex>
#define x real()
#define y imag()
typedef complex<double> point;
*/

typedef long long int64;
int t, tt;
void solve()
{
	string str;
	cin >> str;
	int tmp = 1, ans = tmp;
	char cur = str[0];
	int sz = str.size();
	for (int i = 1; i < sz; i++)
	{
		if (str[i] == cur) tmp++, ans = max(ans, tmp);
		else ans = max(ans, tmp), tmp = 1, cur = str[i];
	}
	cout << ans << endl;
}

int main()
{
	cin >> t;
	while (t--) solve();
	return 0;
}
