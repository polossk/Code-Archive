/****
	*@PoloShen
	*Title:UVaOJ 156
	*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class Word{
public:
	Word():tim(-1){}
	Word(string str){
		ori = str;dic = str;tim = 1;
		transform(dic.begin(), dic.end(), dic.begin(), ::tolower);
		sort(dic.begin(), dic.end());
	}
	string toString(){ return ori; }
	string toDicton(){ return dic; }
	int showTimes(){ return tim; }
	void setTimes(int t){ tim = t; }
	friend bool wcmp(const Word& a, const Word& b);
	friend bool ocmp(const Word& a, const Word& b);
private:
	string ori;
	string dic;
	int tim;
};

bool wcmp(const Word& a, const Word& b){
	return a.dic < b.dic;
}
bool ocmp(const Word& a, const Word& b){
	return a.ori < b.ori;
}

typedef vector<Word> wordlist;
wordlist rbuf;
wordlist pbuf;

void Read(wordlist& rbuf){
	string buf;rbuf.clear();
	while (cin >> buf){
		if (buf == "#") break;
		else {
			Word w(buf);
			rbuf.push_back(w);
		}
	}
	return;
}

void Print(wordlist pbuf){
	for (int i = 0, sz = pbuf.size(); i < sz; ++i)
		cout << pbuf[i].toString() << endl;
	return;
}

void solve(){
	Read(rbuf);
	sort(rbuf.begin(),rbuf.end(),wcmp);
	pbuf.clear();
	int sz = rbuf.size();
	for (int i = 1; i < sz; ++i){
		if (rbuf[i].toDicton() == rbuf[i-1].toDicton()){
			rbuf[i].setTimes(-1);
			rbuf[i-1].setTimes(-1);
		}
		else continue;
	}
	for (int i = 0; i < sz; ++i)
		if (rbuf[i].showTimes() == 1) pbuf.push_back(rbuf[i]);
	sort(pbuf.begin(), pbuf.end(), ocmp);
	Print(pbuf);
}
int main(){
	solve();
    return 0;
}