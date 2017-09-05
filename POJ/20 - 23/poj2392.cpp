/****
	*@Polo-shen
	*
	*/
//#pragma comment(linker,"/STACK:1024000000,1024000000")
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
#define ALG 1

#if DBG
	#include <cstdlib>
	#define pause system("pause")
	#define ShowLine cout<<__LINE__<<">|\t"
	#define dout cout<<__LINE__<<">|\t"
	#define write(x) #x"="<<(x)<<" "
	#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "
#else
	#define pause ;
	#define ShowLine DBG && cout<<__LINE__<<">|\t"
	#define dout DBG && cout<<__LINE__<<">|\t"
	#define write(x) #x"="<<(x)<<" "
	#define awrite(array,num) #array"["<<num<<"]="<<array[num]<<" "
#endif // DBG

#if ALG
	#include <algorithm>
#else
	#ifndef min
		#define min(x,y) ((x)<(y) ? (x) : (y))
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

#define M 405
#define N 40005
#define max(a,b) (a > b ? a : b)
int n,dp[N];
typedef struct number{
	int a;
	int h;
	int c;
}Number;
Number data[M];
int cmp(const void *a,const void *b){
	return ((*(number *)a).a > (*(number *)b).a)? 1 : -1;
}
int main(){
	int i,j,k,C,max;
	scanf("%d",&n);
	for (i=0,max=0;i<n;i++){
		scanf("%d%d%d",&data[i].h,&data[i].a,&data[i].c);
		if (max<data[i].a){
			max=data[i].a;
		}
	}
	int ans=0;
	qsort(data,n,sizeof(data[0]),cmp);
	for (i=0;i <= max;i++){
	dp[i]=0;
	}
	for (i=0;i<n;i++){
		C=data[i].a;
		for (j=0;j<data[i].c;j++){
			for (k=C;k>=data[i].h;k--){
				dp[k]=max(dp[k],dp[k - data[i].h] + data[i].h);
				if (dp[k] > ans){
					ans=dp[k];
				}
			}
		}
    }
    printf("%d\n",ans);
	return 0;
}
