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

void solve(string buf){
	int z=0,o=0,j=0;
	int i=0;
	string::size_type sz=buf.size();
	for (int i=0;i<sz;i++){
		switch(buf[i]){
			case 'Z':{z++;break;}
			case 'O':{o++;break;}
			case 'J':{j++;break;}
		}
	}
	int nzoj=min(min(z,o),j);
	int lz=z-nzoj,lo=o-nzoj,lj=j-nzoj;
	for (int i=0;i<nzoj;i++)printf("ZOJ");
	int mlop=max(max(lz,lo),lj);
	for (int i=0;i<mlop;i++){
		if (lz>0){
			printf("Z");
			lz--;
		}
		if (lo>0){
			printf("O");
			lo--;
		}
		if (lj>0){
			printf("J");
			lj--;
		}
	}
	printf("\n");
}

int main(){
    string buf;
    while (cin>>buf){
		if (buf[0]=='E')return 0;
		else solve(buf);
    }
    return 0;
}
