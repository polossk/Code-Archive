/****
	*@PoloShen
	*Title:UVaOJ 120
	*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<string> num;
deque<int> Stack;
string line;

void Read(){
	istringstream stream(line);
	int tempNum;
	while (stream >> tempNum){
		Stack.push_front(tempNum);
	}
}

void solve(){
	num.clear();
	Stack.clear();
	cout << line << endl;
	num.clear();
	Stack.clear();
	Read();
	for (deque<int>::iterator it = Stack.begin(); it != Stack.end(); it++){
		deque<int>::iterator iMax = max_element(it, Stack.end());
		if (iMax != it){
			if (iMax != Stack.end() - 1){
				reverse(iMax, Stack.end());
				cout << distance(Stack.begin(), iMax) + 1 << ' ';
			}
			reverse(it, Stack.end());
			cout << distance(Stack.begin(), it) + 1 << ' ';
		}
	}
	cout << '0' << endl;
}

int main(){
	while (getline(cin, line)){
		solve();
	}
    return 0;
}