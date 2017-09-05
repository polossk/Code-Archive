/****
	*COPYRIGHT NOTICE 
    *Copyright (c) 2014 
    *All rights reserved
    
	*@author    Shen
	*@name		H
	*@file		G:\My Source Code\比赛与日常练习\0608 - wuyiqi退役赛\H\H.cpp
	*@date		2014/6/8 18:30
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
int a, b, n;

void solve()
{
	a = 0, b = 0, n += 2;
	while (n % 3 == 0) a++, n /= 3;
	while (n % 5 == 0) b++, n /= 5;
	if (n == 1) puts("Yes");
	else puts("No");
	return;
}

int main()
{
	while (~scanf("%d", &n)) solve();
	return 0;
}