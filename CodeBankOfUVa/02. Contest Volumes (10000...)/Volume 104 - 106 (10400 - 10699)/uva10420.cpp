/****
	*@PoloShen
	*Title:Uva 10420
	*/
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
struct conquest{
	string country;
	int number;
	conquest(){country = ""; number = 1;}
};
vector<conquest> conlist;
bool ccmp(const conquest& a, const conquest& b){
	return a.country < b.country;
}

string input(){
	string buf, country;
	getline(cin, buf);
	stringstream stream;
	stream<<buf;
	stream>>country;
	return country;
}

void setdata(string news){
	for (int i = 0, sz = conlist.size(); i < sz; ++i){
		if (conlist[i].country == news){
			++conlist[i].number;
			return;
		}
	}
	conquest newd;
	newd.country = news;
	conlist.push_back(newd);
	return;
}

void print(){
	for (int i = 0, sz = conlist.size(); i < sz; ++i){
		cout<<conlist[i].country<<" "<<conlist[i].number<<endl;
	}
}

void solve(int T){
	while (T--){
		string news = input();
		setdata(news);
	}
	sort(conlist.begin(), conlist.end(), ccmp);
	print();
	return;
}

int main(){
//#define __LOCAL__
#ifdef __LOCAL__
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif // __LOCAL__
	int T;
	scanf("%d",&T);getchar();
	solve(T);
    return 0;
}