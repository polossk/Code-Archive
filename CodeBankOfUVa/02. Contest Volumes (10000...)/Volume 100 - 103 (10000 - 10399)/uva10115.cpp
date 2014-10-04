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

#define DBG 0
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
string origin;
vector<string> dict;
vector<string> reff;

void Read(int rules){
	string temp;
	for (int i = 0; i < rules; i++){
		getline(cin, temp);
		dict.push_back(temp);
		getline(cin, temp);
		reff.push_back(temp);
	}
	getline(cin, origin);
}

void AutoEdit(int rules){
	for (int i = 0; i < rules; i++){
		while (1){
			int pos = origin.find(dict[i]);
			if (pos != string::npos){
				origin.replace(pos, dict[i].size(), reff[i]);
				//origin.erase(origin.begin() + pos, origin.begin() + pos + dict[i].size());
				//origin.insert(pos, reff[i]);
			}
			else break;
		}
	}
}

void solve(int rules){
	dict.clear();
	reff.clear();
	origin.clear();
	Read(rules);
	AutoEdit(rules);
	cout<<origin<<endl;
}

int main(){
//#define __LOCAL__
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
	int rules = 0;
	while (cin>>rules && rules){
		getchar();
		solve(rules);
	}
    return 0;
}
