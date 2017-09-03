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
#define ShowLine DBG && cout<<__LINE__<<">|\t"
#define dout DBG && cout<<__LINE__<<">|\t"
#define write(x) #x" = "<<(x)<<" "
#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "

void sprint(string s){
	if (DBG){
		string::size_type sz=s.size();
		for (int i=0;i<sz;i++){
			printf("%c",s[i]);
		}
		puts("|< EOL >|\n");
	}
	else return;
}

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

/***
	*Title:
	*
	*/

void slove(string a){
	int i,nz,nj,k;
	string::size_type sz=a.size();
	nz=0;nj=0;
	for(i=0;i<sz;i++){
		if(a[i]=='z')nz++;
		if(a[i]=='j')nj++;
	}
	if(nz==1 && nj==1){
		for(i=0;i<sz;i++){
			if(a[i]=='z')break;
		}
		nz=i;
		for(i=nz;i<sz;i++){
			if(a[i]=='j')break;
		}
		nj=i;
		k=nj-nz-1;
		if (k>=1){
			if ((k*nz)==(sz-1-nj)){
				cout<<"Accepted"<<endl;
			}
			else {
				cout<<"Wrong Answer"<<endl;
			}
		}
		else {
			cout<<"Wrong Answer"<<endl;
		}
	}
	else {
		cout<<"Wrong Answer"<<endl;
	}
}

int main(){
	string s;
	while(cin>>s){
		slove(s);
	}
	return 0;
}
