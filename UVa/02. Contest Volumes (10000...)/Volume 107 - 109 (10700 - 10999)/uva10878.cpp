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

//#define __LOCAL__

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

const int p[8] = {128, 64, 32, 16, 8, 4, 2, 1};
const string blank = "___________";

char decode(string msg){
	int j = 0;
	int code = 0;
	for (int i = 1; i < 6; i++){
		code += (msg[i] == 'o')? p[i-1]: 0;
	}
	for (int i = 7; i < 10; i++){
		code += (msg[i] == 'o')? p[i-2]: 0;
	}
	return (char)code;
}
void solve(){
	string s;
	getline(cin, s);
	while (1){
		getline(cin, s);
		if (s != blank){
			char ch = decode(s);
			if (ch != '\0')	printf("%c", ch);
		}
		else break;
	}
}
int main(){
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
	solve();
    return 0;
}
