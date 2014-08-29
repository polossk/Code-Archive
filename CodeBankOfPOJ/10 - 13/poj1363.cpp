#include <iostream>
#include <stack>
using namespace std;
int a[1005];
int main()
{
    stack<int> s;
    int i,j,n;
    bool flag;
    while (cin >> n && n)
	{
        while (cin >> a[0] && a[0])
		{
            for(i = 1; i < n; i++) cin >> a[i];
            while (!s.empty()) s.pop();
            i = 0; j = 1;
            flag = 1;
            while (i < n)
			{
                if (a[i] == j) { i++; j++; }
                else if (!s.empty() && s.top() == a[i]) { s.pop(); i++; }
                else if (j <= n) s.push(j++);
                else { flag = 0;  break; }
            }
            cout << ((flag)? "Yes": "No") << endl;
        }
        cout << endl;
    }
    return 0;
}