#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

string ms[19] = {
	"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
	"mol", "chen", "yax", "zac", "ceh", "mac",
	"kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

string ds[20] = 
{
	"imix", "ik", "akbal", "kan", "chicchan", "cimi", 
	"manik", "lamat", "muluk", "ok", "chuen", "eb", "ben",
	"ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

const int haab = 365;
const int tzolkin = 260;

int main(){
    int t; cin >> t;
    cout << t << endl;
    while (t--)
	{
		int dd, mm, yy; string month;
		int sday; char ch;
		cin >> dd >> ch >> month;
		for (int i = 0; i < 19; i++) if (ms[i] == month) mm = i;
		cin >> yy;
		int tdd = 1, tyy, tmp, idx = 0;
		sday = haab * yy + 20 * mm + dd + 1;
		tyy = sday / tzolkin; tmp = sday % tzolkin;
		if (tmp == 0) { tmp = 260; tyy--; }
		for (int i = 1; i <= tmp; i++)
		{
			if (i == tmp)
				cout << tdd << " " << ds[idx] << " " << tyy << endl;
			else
			{
				tdd++; if (tdd == 14) tdd = 1;
				idx++; if (idx == 20) idx = 0;
			}
		}
    }
    return 0;
}