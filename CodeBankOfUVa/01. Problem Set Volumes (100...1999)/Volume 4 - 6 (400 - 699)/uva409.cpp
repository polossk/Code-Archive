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

typedef string keyword;
typedef list<keyword> keywords;
keywords kws;
keywords query;

typedef string sentence;
typedef vector<sentence> sentences;
sentences origin;
//sentences fortest;

keywords Trans2Test(sentence ori){
	int sz = ori.size();
	int i = 0;
	sentence os = ori;
	keywords res;res.clear();
	keyword temp;temp.clear();
	for (; i < sz; i++){
		if (isalpha(os[i])){
			os[i]=toupper(os[i]);
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

void Read(int k, int l){
	getchar();
	kws.clear();
	origin.clear();
	for (int i = 0; i < k; i++){
		keyword temp;
		getline(cin, temp);
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		kws.push_back(temp);
	}
	kws.unique();kws.sort();
	for (int i = 0; i < l; i++){
		sentence temp;
		getline(cin, temp);
		origin.push_back(temp);
	}
}

void solve(int casenum, int k, int l){
	cout<<"Excuse Set #"<<casenum<<endl;
	Read(k, l);
	int cn[l];//cn means corresponding number
	int maxcn = -1;//means maxinum of corresponding number
	for (int i = 0; i < l; i++){
		query.clear();cn[i] = 0;
		query = Trans2Test(origin[i]);
		for (keywords::iterator it = query.begin(); it != query.end(); it++){
			for (keywords::iterator jt = kws.begin(); jt != kws.end(); jt++){
				if (*(it) == *(jt)){
					cn[i]++;break;
				}
			}
		}
		maxcn = (maxcn > cn[i])? maxcn: cn[i];
	}

	for (int i = 0; i < l; i++){
		if (cn[i] == maxcn){
			cout<<origin[i]<<endl;
		}
	}
	cout<<endl;
}

int main(){
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
	int tt = 0;
	int k = 0, l = 0;
	while (scanf("%d %d", &k, &l)!=EOF){
		solve(++tt, k, l);
	}
    return 0;
}