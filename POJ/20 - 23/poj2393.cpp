#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;
long long n, s, sum = 0;
long long f[10010], y[10010];
int main()
{
	scanf ("%I64d%I64d",&n, &s);
	for (int i = 0; i < n; i++)
	{
		  scanf ("%I64d%I64d", &f[i], &y[i]); 
	}
	for (int i= 1; i < n; i++)
	{
		f[i] = min(f[i - 1] + s, f[i]);
	}
	for (int i = 0; i < n; i++)
	{
		sum += f[i] * y[i];
	}
	cout << sum << endl;
	return 0; 
}