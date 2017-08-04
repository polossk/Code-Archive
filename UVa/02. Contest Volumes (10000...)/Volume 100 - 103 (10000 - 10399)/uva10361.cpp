/****
	*@PoloShen
	*Title:
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <deque>
#include <queue>

#define DBG 1
#define ALG 0
#define USING_STL_STRING	1
#define USING_STL_VECTOR	1
#define USING_STL_LIST		1
#define USING_STL_STACK		1
#define USING_STL_DEQUE		1
#define USING_STL_QUEUE		1

#if DBG
	#include "F:\\My Source Code\\debug.h"
#else
	#define __DBG 0 &&
#endif // DBG

#if ALG
	#include <algorithm>
#else
	#ifndef min
		#define min(x,y) ((x) < (y) ? (x) : (y))
	#endif
	#ifndef max
		#define max(x,y) ((x) > (y) ? (x) : (y))
	#endif
#endif // ALG

string s[5];
string l[2];
string c[2];
const char judge[5] = {'<', '>', '<', '>','\0'};

void Clear(){
	for (int i = 0; i < 5; i++){
		s[i].clear();
	}
	for (int i = 0; i < 2; i++){
		l[i].clear();
		c[i].clear();
	}
	return;
}

void Read(){
	getline(cin, l[0]);
	getline(cin, l[1]);
	return;
}

void Trans(){
	// deal with l[0]
	int sz = l[0].size();
	int judgeflag = 0;
	for (int i = 0; i < sz; i++){
		if (l[0][i] == judge[judgeflag]){
			judgeflag++;
		}
		else {
			s[judgeflag] += l[0][i];
		}
	}

	//create c[0]
	c[0] = s[0] + s[1] + s[2] + s[3] + s[4];

	// deal with l[1]
	sz = l[1].size();
	c[1].assign(l[1], 0, sz - 3);
	c[1] += s[3] + s[2] + s[1] + s[4];
}

void Print(){
	cout<<c[0]<<endl;
	cout<<c[1]<<endl;
}

void solve(){
	Clear();
	Read();
	Trans();
	Print();
}

int main(){
	int T;
	cin>>T;
	getchar();
	while (T--){
		solve();
	}
    return 0;
}
