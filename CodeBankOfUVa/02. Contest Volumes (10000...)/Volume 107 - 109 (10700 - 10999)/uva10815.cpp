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
#define ALG 1
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

typedef string word;
typedef list<word> words;
typedef string sentence;
words result;
sentence origin;

words Trans2Test(sentence ori){
	int sz = ori.size();
	int i = 0;
	sentence os = ori;
	words res;res.clear();
	word temp;temp.clear();
	for (; i < sz; i++){
		if (isalpha(os[i])){
			os[i]=tolower(os[i]);
		}
		else{
			os[i]=' ';
		}
	}
	os[sz]='\0';
	for (i = 0; i < sz; i++){
		if (os[i] == ' '){
			if (temp.empty()){
				continue;
			}
			else{
				res.push_back(temp);
				temp.clear();
			}
		}
		else{
			temp += os[i];
		}
	}
	if (!temp.empty()){
		res.push_back(temp);
		temp.clear();
	}
	return res;
}
void solve(){
	while (getline(cin, origin)){
		words newwords = Trans2Test(origin);
		result.merge(newwords);
	}
	result.sort();
	result.unique();
	for (words::iterator it = result.begin(); it != result.end(); it++){
		cout<<*(it)<<endl;
	}
}

int main(){
//#define __LOCAL__
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
	solve();
    return 0;
}
