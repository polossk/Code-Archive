/****
	*@PoloShen
	*Title:uva 10499
	*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	double n;
	while (scanf("%lf", &n) && n >= 0){
	    if (n<=1)
			printf("0%%\n");
		else
			printf("%.0lf%%\n", 25 * n);
	}
	return 0;
}