/****
	*COPYRIGHT NOTICE 
    *Copyright (c) 2014 
    *All rights reserved
    
	*@author    Shen
	*@name		F
	*@file		G:\My Source Code\比赛与日常练习\0608 - wuyiqi退役赛\F\F.cpp
	*@date		2014/6/8 20:21
	*/

//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
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

const double p6 = 1.0 / 6.0;
double res[100005];

int t, q;

void init()
{
	int i = 1, j = 7;
	double tmp = 36.0;
	for (; j < 100005; i++, j++)
	{
		res[j] = p6 * (6.0 + tmp);
		tmp = tmp + res[j] - res[i];
	}
}
void solve()
{
	scanf("%d", &q);
	printf("%.2lf\n", res[q]);
}

int main()
{
	res[1] = res[2] = res[3] = res[4] = res[5] = res[6] = 6;
	init();
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
