/****
	*@PoloShen
	*Title:UVaOJ 10010 Where's Waldorf?
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define LOCAL 0
#include <vector>
//#include <list>
//#include <stack>
//#include <deque>
//#include <queue>

#include <cctype>

#define DBG 0
#define ALG 1
#define USING_STL_STRING	1
#define USING_STL_VECTOR	1
#define USING_STL_LIST		0
#define USING_STL_STACK		0
#define USING_STL_DEQUE		0
#define USING_STL_QUEUE		0

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
namespace UVaOJ10010{
	const int Direction_cases = 8;
	int Direction[Direction_cases][2]{
		{-1, +1}, {0, +1}, {+1, +1},
		{-1,  0},		   {+1, 0 },
		{-1, -1}, {0, -1}, {+1, -1}
	};
	int N, M;
	int index;
	vector<string> dict;
	vector<string> words;
	void Read(){
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			string line;
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);
			dict.push_back(line);
		}
		cin >> index;
		for (int i = 0; i < index; i++){
			string word;
			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			words.push_back(word);
		}
	}

	bool inbound(int x, int L, int R){
		return (x <= R) && (x >= L);
	}

	void SearchWord(string word){
		int sz = word.size();
		bool flag = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (dict[i][j] == word[0]){
					for (int d = 0;d < Direction_cases; d++){
						int searched = 1;
						for (int k = 1; k < sz; k++){
							int row = i + Direction[d][0] * k;
							int col = j + Direction[d][1] * k;
							if (inbound(row, 0, N - 1) && inbound(col, 0, M - 1)){
								;
							}
							else break;
							if (dict[row][col] == word[k]){
								searched++;
							}
							else break;
						}
						if(searched == sz){
							printf("%d %d\n", i+1, j+1);
							flag = 1;
							return;
						}
						else{
							continue;
						}
					}
				}
				else continue;
			}
		}
		return;
	}

	void Clear(){
		dict.clear();
		words.clear();
	}

	void Solve(){
		Clear();
		Read();
		for (int i = 0; i < index; i++){
			SearchWord(words[i]);
		}
	}
};
using namespace UVaOJ10010;


int main(){
	int T;
	scanf("%d",&T);
	#if LOCAL
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif // LOCAL
	while (T--){
		UVaOJ10010::Solve();
		if (T > 0){
			printf("\n");
		}
	}
    return 0;
}
