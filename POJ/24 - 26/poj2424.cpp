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


struct table{
	int end[101];
	int wait_time[101];
};

int main(){
	int t[3],n,clock,minute,time,people;
	char s[10];
	while (1){
		struct table tab[3];
		int k[3]={1,1,1},sum= 0;
		for(n=0;n<3;n++){
			memset(tab[n].end,0,sizeof(tab[n].end));
			memset(tab[n].wait_time, 0, sizeof(tab[n].wait_time));
		}
		cin>>t[0]>>t[1]>>t[2];
		getchar();    // 消去回车。
		if(t[0]==0 && t[1]==0 && t[2]==0) break;
		while(1){
			gets(s);
			if(s[0] == '#') break;
			clock=10*(s[0]-'0') + (s[1]-'0');
			minute=10*(s[3]-'0') + (s[4]-'0');
			time= 60*(clock-8) + minute;
			people=s[6]-'0';
			if(people==1 || people==2)  n = 0;
			else if(people==3 || people==4)  n = 1;
			else if(people==5 || people==6)  n = 2;
			if(time >= tab[n].end[k[n]]){
				tab[n].end[k[n]] = time + 30;
				k[n] ++;
				if(k[n] > t[n]) k[n] = 1;
				sum += people;
			}
			else if(time >= tab[n].wait_time[k[n]]){
				tab[n].wait_time[k[n]] = tab[n].end[k[n]];
				tab[n].end[k[n]] += 30;
				k[n] ++;
				if(k[n] > t[n])  k[n] = 1;
				sum+=people;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
