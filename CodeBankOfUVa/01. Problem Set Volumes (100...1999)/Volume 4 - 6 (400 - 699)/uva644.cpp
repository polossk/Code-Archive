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
vector<string> dict;
const string endflag = "9";
bool cmp(string str1, string str2){
	int len1 = str1.size();
	int len2 = str2.size();
	int len = (len1 > len2)? len2: len1;
	for (int i = 0; i < len; i++){
		if (str1[i] != str2[i])return 0;
		else continue;
	}
	return 1;
}

void Print(bool printflag, int casenum){
	if (!printflag){
		printf("Set %d is immediately decodable\n", casenum);
	}
	else{
		printf("Set %d is not immediately decodable\n",casenum);
	}
}

bool Judge(){
	int sz = dict.size();
	for (int i = 0; i < sz; i++){
		for (int j = i + 1; j < sz; j++){
			bool temp = cmp(dict[i], dict[j]);
			if (temp)return temp;
			else continue;
		}
	}
	return 0;
}

bool solve(int casenum){
	dict.clear();
	string str;
	bool termflag = 1;
	while (getline(cin, str)){
		if (str != endflag){
			dict.push_back(str);
		}
		else{
			bool flag = 1;
			flag = Judge();
			Print(flag, casenum);
			return 0;
		}
	}
	return termflag;
}

int main(){
//#define __LOCAL__
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
	int casenum = 0;
	while (1){
		bool termflag = solve(++casenum);
		if (termflag)break;
	}
    return 0;
}
