#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
int t, tt;

void solve()
{
	double x, y;
	cin >> x >> y;
	double s = pi * (x * x + y * y);
	int r = int(s / 100.0 + 1.0);
	printf("Property %d: This property will begin eroding in year %d.\n", ++tt, r);
}

int main()
{
	cin >> t;
	while (t--) solve();
	cout << "END OF OUTPUT." << endl;
	return 0;
}