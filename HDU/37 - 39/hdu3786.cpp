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
int ar[27][2];
int dfs(int n,int r,int d){
	d++;
	if (n==27 || n==0){
		return 0;
	}
	if (ar[n][0]==r || ar[n][1]==r){
		return d;
	}
	int res=0;
    if ((res=dfs(ar[n][0],r,d))!=0){
		return res;
	};
    if ((res=dfs(ar[n][1],r,d))!=0){
		return res;
	};
	return 0;
}

void sDLL(string s){
	for(int i=1;i!=3;i++){
		if(s[i]=='-'){
			ar[s[0]-'A'+1][i-1]=27;
		}
		else{
			ar[s[0]-'A'+1][i-1]=s[i]-'A'+1;
		}
	}
}

void solve(int n){
	int res,r;
	bool flag=false;
	string s;
	for (int i=0;i!=n;i++){
		cin>>s;
		if ((res=dfs((s[0]-'A'+1),s[1]-'A'+1,0))!=0){
			if (res==1){
				cout<<"child"<<endl;
			}
			else if (res==2){
				cout<<"grandchild"<<endl;
			}
			else {
				for (int i=0;i!=res-2;i++){
					cout<<"great-";
				}
				cout<<"grandchild"<<endl;
			}
		}
		else if ((res=dfs(s[1]-'A'+1,s[0]-'A'+1,0))!=0){
			if (res==1){
				cout<<"parent"<<endl;
			}
			else if (res==2){
				cout<<"grandparent"<<endl;
			}
			else {
				for (int i=0;i!=res-2;i++){
					cout<<"great-";
				}
				cout<<"grandparent"<<endl;
			}
		}
		else{
			cout<<"-"<<endl;
		}
	}
}



int main(){
    int m,n;
    while (cin>>m>>n && (m && n)){
		string s;
		memset(ar,0,sizeof(ar));
		for (int i=0;i<m;i++){
			cin>>s;
			sDLL(s);
		}
		solve(n);
    }
    return 0;
}
