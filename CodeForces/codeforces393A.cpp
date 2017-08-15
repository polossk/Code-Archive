/****
	*@PoloShen
	*Title:A
	*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N, M, ans, cnt ;
string s;
int main()
{
	int i, j ;
	getline(cin, s);
	N = s.size();
	ans = N;
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 'n') cnt++;
	ans = min(ans, (cnt - 1) / 2);
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 'i') cnt++;
	ans = min(ans, cnt);
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 't') cnt++;
	ans = min(ans, cnt);
	for (i = 0, cnt = 0; i < N; i++)
		if (s[i] == 'e') cnt++;
	ans = min(ans, cnt / 3);
	cout << ans << endl;
	return 0 ;
}