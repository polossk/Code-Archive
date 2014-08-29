/****
	*@Polo-shen
	*
	*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
//#include <algorithm>
#include <cmath>
//#include <iomanip>
//#include <fstream>
//#include <cstdlib>
#include <vector>
//#include <list>
//#include <set>
//#include <map>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<" "
#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif


const int MAXN = 3;
const int MAXM = 2;
/***
	*Title:HDU4565
	*
	*/
struct Matrax{
	int n,m;
	int64 mat[MAXN][MAXM];
	Matrax():n(-1),m(-1){}
	Matrax(int _n,int _m):n(_n),m(_m){
		memset(mat,0,sizeof(mat));
	}
	void Unit(int _s){
		n=_s;m=_s;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				mat[i][j]=(i==j)?1:0;
			}
		}
	}
	void print(){
		cout<<write(n)<<write(m)<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cout<<" "<<mat[i][j];
			}
			cout<<endl;
		}
	}
};

Matrax add_mod(const Matrax& a,const Matrax& b,const int64 mod){
	Matrax ans(a.n,a.m);
	for (int i=0;i<a.n;i++){
		for (int j=0;j<a.m;j++){
			ans.mat[i][j]=(a.mat[i][j]+b.mat[i][j])%mod;
		}
	}
	return ans;
}

Matrax mul(const Matrax& a,const Matrax& b){
	Matrax ans(a.n,b.m);
	for (int i=0;i<a.n;i++){
		for (int j=0;j<b.m;j++){
			int64 tmp=0;
			for (int k=0;k<a.m;k++){
				int64 res=a.mat[i][k]*b.mat[k][j];
				tmp+=res;
			}
			ans.mat[i][j]=tmp;
		}
	}
	return ans;
}

Matrax mul_mod(const Matrax& a,const Matrax& b,const int64 mod){
	Matrax ans(a.n,b.m);
	for (int i=0;i<a.n;i++){
		for (int j=0;j<b.m;j++){
			int64 tmp=0;
			for (int k=0;k<a.m;k++){
				tmp+=(a.mat[i][k]*b.mat[k][j])%mod;
			}
			ans.mat[i][j]=tmp%mod;
		}
	}
	return ans;
}

Matrax pow_mod(const Matrax& a,int64 k,int64 mod){
	Matrax p(a.n,a.m),ans(a.n,a.m);
	p=a;ans=a;
	ans.Unit(a.n);
	if (k==0){
		return ans;
	}
	else if (k==1){
		return a;
	}
	else {
		while (k){
			if (k&1){
				ans=mul_mod(ans,p,mod);
				k--;
			}
			else {
				k/=2;
				p=mul_mod(p,p,mod);
			}
		}
		return ans;
	}
}

void solve(int64 a,int64 _b,int64 n,int64 m){
	double b=sqrt(double(_b));
	//cout<<write(a)<<write(b)<<endl;
	//cout<<write(n)<<write(m)<<endl;
	/*
	   2*a  b*b-a*a
	F=(            )
		1      0
	*/
	Matrax F(2,2);
	F.mat[0][0]=2*a%m;F.mat[0][1]=(_b-a*a)%m;
	F.mat[1][0]=1;F.mat[1][1]=0;
	//F.print();
	/*
		2*a
	K1=(   )
		 2
	*/
	Matrax K1(2,1);
	K1.mat[0][0]=2*a;
	K1.mat[1][0]=2;
	//K1.print();
	/*
		 Sn
	Kn=(    )
		Sn-1
	*/
	Matrax Kn(2,1);
	Matrax tmp(2,2);
	tmp=pow_mod(F,n-1,m);
	//tmp.print();
	Kn=mul_mod(tmp,K1,m);
	//cout<<"Kn";Kn.print();
	int64 ans=(Kn.mat[0][0]%m);
	cout<<((ans<0)?(ans+m):(ans))<<endl;
	return;
}

int main(){
	int64 a,b,n,m;
	while (cin>>a>>b>>n>>m){
		solve(a,b,n,m);
	}
    return 0;
}
