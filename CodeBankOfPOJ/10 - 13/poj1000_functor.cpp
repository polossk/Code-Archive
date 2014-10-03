#include <iostream>
using namespace std;

class _functor{
public:
	int operator()(int x, int y) { return x + y; }
}Plus;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << Plus(a,b) << endl;
	return 0;
}