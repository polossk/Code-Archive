#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
typedef long long int64;

string transform(int x, int y, string s)
{
	string res = "";
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-') continue;
		if (s[i] >= '0' && s[i] <= '9')
			sum = sum * x + s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			sum = sum * x + s[i] - 'A' + 10;
		else 
			sum = sum * x + s[i] - 'a' + 36;
	}
	while (sum)
	{
		char tmp = sum % y; sum /= y;
		if (tmp <= 9) tmp += '0';
		else if (tmp<=35) tmp += 'A' - 10;
		else tmp += 'a' - 36;
		res += tmp;
	}
	if (res.size() == 0) res = "0";
	if (s[0] == '0') res = '-' + res;
	return res;
}

class trans{
public:
	int t[555], A[555];
	char d[555];
	trans()
	{
		memset(t,0,sizeof(int));
		memset(A,0,sizeof(int));
		memset(d,0,sizeof(char));
	}
	string transf(int a, int b, string s)
	{
		int i,k,l;
		for (k = i = s.size(); 0 < i--; )
			t[k - 1 - i] = s[i] - ( s[i] < 58? 48: ( s[i] < 97? 55: 61 ) );
		
		for (l = 0; k; )
		{
			for (i = k; 1 < i--; ) t[i - 1] += t[i] % b * a, t[i] /= b;
			A[l++] = t[0] % b; t[0] /= b;
			for ( ; 0 < k && !t[k - 1]; k--);
		}
		for (d[l] = i = 0; i < l; i++)
			d[l - 1 - i] = A[i] + ( A[i] < 10? 48: ( A[i] < 36? 55: 61 ) );
		string res = d;
		return res;
	}
}tr;
int main()
{
	string a1, a2;
	int a, b, T; cin >> T;
	while(T--){
		cin >> a >> b >> a1;
		a2.clear();
		a2 = tr.transf(a, b, a1);
		cout << a << " " << a1 << endl;
		cout << b << " " << a2 << endl;
		cout << endl;
	}
    return 0;
}