#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

inline int rdi(){int d; scanf("%d", &d); return d;}

const int S = 12*60*60;

struct Frac {
	int n, d;
	Frac(int nn=0, int dd=1): n(nn), d(dd) {}
	bool operator<=(Frac r)const { return n*r.d<=r.n*d; }
	bool operator<(Frac r) const { return n*r.d< r.n*d; }
	Frac operator+(Frac r) const { return Frac(n*r.d+r.n*d, d*r.d); }
	Frac operator-(Frac r) const { return Frac(n*r.d-r.n*d, d*r.d); }
	Frac operator*(Frac r) const { return Frac(n*r.n      , d*r.d); }
	Frac operator/(Frac r) const { return Frac(n*r.d      , d*r.n); }
}axis, raxis, be, ed;
set<Frac> ans;
set<Frac>::iterator it;
istream& operator>>(istream& is, Frac& t) {
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	t = Frac(h*3600+m*60+s);
	return is;
}
ostream& operator<<(ostream& os, const Frac& t) {
	printf("%02d:%02d:%02d", (int)(t.n/(t.d*3600)), (int)(t.n/(t.d*60)%60), (int)(t.n/t.d%60));
	if(t.n % t.d) printf(" %d/%d", (int)(t.n%t.d), (int)t.d);
	puts("");
	return os;
}
void update_ans(Frac t){
	if(be<=t && t<=ed) ans.insert(t);
}

int main(){
	int tt = 0, T;
	scanf("%d", &T);
	while (T--){
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		axis = Frac(h*3600+m*60+s);
		scanf("%d:%d:%d", &h, &m, &s);
		be = Frac(h*3600+m*60+s);
		scanf("%d:%d:%d", &h, &m, &s);
		ed = Frac(h*3600+m*60+s);
		ans.clear();
		raxis = Frac(axis.n<(S>>1)?axis.n+(S>>1):axis.n-(S>>1));
		for (int ht = 0; ht <= 12; ++ht){
			update_ans(( axis*2-ht*3600)/13+ht*3600);
			update_ans((raxis*2-ht*3600)/13+ht*3600);
		}
		printf("Case %d: %d\n", ++tt, (int)(ans).size());
		for(it = ans.begin(); it != ans.end(); ++it)cout << *it;
	}
	return 0;
}