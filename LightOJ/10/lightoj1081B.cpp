#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#define ll __int64
//#define ll long long
#define PI acos(-1.0)
#define INF 2000000000
using namespace std;
int f_min(int x,int y){return x<y?x:y;}
int f_max(int x,int y){return x>y?x:y;}
int f_abs(int x){return x<0?-x:x;}
int N,Q,num[500][500];
int stb[500][500][10];
int f_max(int a,int b,int c,int d){
	return f_max(f_max(a,b),f_max(c,d));
}
void get_data(){
	int i,j,k,l;
	scanf("%d%d",&N,&Q);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&num[i][j]);
			stb[i][j][0]=num[i][j];
		}
	}
	for(k=1,l=2;l<=N;k++,l<<=1){
		for(i=0;i+l-1<N;i++){
			for(j=0;j+l-1<N;j++){
				stb[i][j][k]=f_max(stb[i][j][k-1],stb[i+(l>>1)][j][k-1],stb[i][j+(l>>1)][k-1],stb[i+(l>>1)][j+(l>>1)][k-1]);
			}
		}
	}
}
void run(){
	int xi,xj,xl,k,l;
	while(Q--){
		scanf("%d%d%d",&xi,&xj,&xl);xi--;xj--;
		k=log(xl*1.0)/log(2.0);l=1<<k;
		printf("%d\n",f_max(stb[xi][xj][k],stb[xi][xj+xl-l][k],stb[xi+xl-l][xj][k],stb[xi+xl-l][xj+xl-l][k]));
	}
}
int main(){
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		get_data();
		printf("Case %d:\n",i);
		run();
	}
	return 0;
}