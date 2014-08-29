#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
typedef long long int64;

enum {
	A = 'A',B,C,D,E,F,G,
	H,I,J,K,L,M,N,
	O,P,Q,R,S,T,
	U,V,W,X,Y,Z
};

enum {
	underscore = '_',
	period = '.',
	comma = ',',
	questionmark = '?'
};

char morseCode[26][6] =
{
	".-","-...","-.-.","-..",".","..-.","--.",
	"....","..",".---","-.-",".-..","--","-.",
	"---",".--.","--.-",".-.","...","-",
	"..-","...-",".--","-..-","-.--","--.."
};

char isMorseCode(string s){
	int i;
	char res;
	for (i = A; i <= Z; i++)
	{
		if (morseCode[i - 'A'] == s)
		{
			res = (char)i;
			break;
		}
	}
	if (s == "..--") res = '_';
	else if (s == "---.") res = '.';
	else if (s == ".-.-") res = ',';
	else if (s == "----") res = '?';
	return res;
}

char* isString(int c)
{
	switch (c)
	{
		case underscore:   return "..--";
		case period:       return "---.";
		case comma:        return ".-.-";
		case questionmark: return "----";
		default: return morseCode[c - 'A'];
	}
}

void solve(int t, string msg)
{
	printf("%d: ", t);
	int each_code[100];
	string s;
	string tmp="";
	int i, sz=msg.size();
	for (int i = 0; i < sz; i++)
	{
		s = isString(msg[i]);
		each_code[i] = s.size();
		tmp += s;
	}
	for (i = sz - 1; i >= 0; i--)
	{
		printf("%c", isMorseCode(tmp.substr(0, each_code[i])));
		tmp = tmp.substr(each_code[i]);
	}
	printf("\n");
}

int main()
{
	int T,tt=0;
	string s;
	scanf("%d", &T);
	while (T--)
	{
		cin >> s;
		solve(++tt, s);
	}
    return 0;
}