#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
class dna
{
public:
	string data; int code;
	dna (string src = "")
	{
		data = src; code = 0;
		int sz = src.size ();
		for (int i = 0; i < sz; i++) for (int j = i + 1; j < sz; j++)
			if (src[i] > src[j]) code++;
	}
	inline bool operator<(const dna& b) const { return code<b.code; }
	friend ostream& operator<<(ostream& os, const dna& n);
};

const int MaxN = 64;
const int MaxM = 128;
dna data[MaxM];
int n, m;

ostream& operator<< (ostream& os,const dna& n){ return os << n.data; }

int main()
{
    cin >> n >> m;
    string str;
	for (int i = 0; i < m; i++){
		cin >> str;
		data[i] = dna(str);
	}
	sort (data, data + m);
	for (int i = 0; i < m; i++)
		cout << data[i] << endl;
    return 0;
}