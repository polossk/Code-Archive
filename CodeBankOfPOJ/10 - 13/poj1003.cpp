#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    double n, sum = 0;
    while (cin >> n)
	{
        if (n == 0) break;
        sum = 0;
        for(int i = 2; ; i++)
		{
            sum += 1 / double(i);
            if (sum > n)
			{
                cout << i - 1 << " card(s)" << endl;
                break;
            }
        }
    }
    return 0;
}