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
#define ALG 0

#if DBG
	#include <cstdlib>
	#define pause system("pause")
	#define ShowLine cout<<__LINE__<<">|\t"
	#define dout cout<<__LINE__<<">|\t"
	#define write(x) #x" = "<<(x)<<" "
	#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "
#else
	#define pause ;
	#define ShowLine DBG && cout<<__LINE__<<">|\t"
	#define dout DBG && cout<<__LINE__<<">|\t"
	#define write(x) #x" = "<<(x)<<" "
	#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "
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

/***
	*Title:
	*
	*/

struct Point{
	int x;int y;
}p[1000];

int mul(int a,int b,int c){
	int t;
    t=(p[a].x-p[c].x)*(p[b].y-p[c].y)-(p[b].x-p[c].x)*(p[a].y-p[c].y);
    return t;
}

void solve(int n){
	int t=0;
	for (int i=0;i<n;i++){
		t=mul(i%n,(i+1)%n,(i+2)%n);
		if (t<0){
			break;
		}
	}
	if (t>=0){
		printf("convex\n");
	}
	else {
		printf("concave\n");
	}
}

int main(){
	int n;
	while (cin>>n && n){
		for (int i=0;i<n;i++){
			scanf(" %d %d",&p[i].x,&p[i].y);
		}
		solve(n);
	}
    return 0;
}
