/****
	*@PoloShen
	*Title:UVaOJ 400
	*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> wl;

void Read(int num, int& maxl){
	string str; maxl = 0; wl.clear();
	while (num--){
		cin >> str;
		wl.push_back(str);
		int l = str.size();
		if (l > maxl) maxl = l;
	}
}

inline void strPrint(string s, int bufsize){
	int sz = s.size();
	int nspace = bufsize - sz;
	printf("%s", s.c_str());
	while (nspace--) printf(" ");
}

void Print(int n, int c, int r, int maxl){
	printf("------------------------------------------------------------\n");
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int tmp = j * r + i;
			if (tmp >= n) continue;
			if (tmp >= ((int)((n-1)/r))*r)
				strPrint(wl[tmp], maxl);     // 如果为最后一列
			else
				strPrint(wl[tmp], maxl + 2);
		}
		printf("\n");
	}
}

void solve(int n){
	int maxl = 0;
	Read(n, maxl);
	sort(wl.begin(),wl.end());
	int c = 0, r = 0;
	c = 62 / (maxl + 2);
	r = (n - 1) / c + 1;
	Print(n, c, r, maxl);
}

int main(){
	int n = 0;
	while (cin >> n) solve(n);
    return 0;
}