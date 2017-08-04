#include<iostream>
using namespace std;
void print_num(int n)
{
	for (int i = 0; i < n; i++)
		cout << n;
	cout << endl;
}
void print_wave(const int n)
{
	for (int i = 1; i < 2 * n; i++)
	{
		if (i <= n)
			print_num(i);
		else
			print_num(2 * n - i);
	}
}
int main()
{
	int n,a,b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		while (b--)
		{
		    print_wave(a);
			if (n == 0 && b == 0) return 0;
			else cout << endl;
		}
	}
}
