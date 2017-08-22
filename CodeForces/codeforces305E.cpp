#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
//#include <cstdlib>
//#include <set>

using namespace std;
typedef long long int64;

#define DBG 0
#define ShowLine DBG && cout<<__LINE__<<">>| "
#define dout DBG && cout<<__LINE__<<">>| "
#define write(x) #x" = "<<(x)<<", "

int grundy[5001],pos[10001];

int main() {
	string s;
	int n,i,j;
	for (i=3;i<=5000;i++) {
		for (j=1;j<=i/2;j++)
			pos[grundy[j]^grundy[i-j-1]]=i;
		for (j=0;pos[j]==i;j++);
		grundy[i]=j;
	}
	cin>>s;
	n=s.size();
	for (i=1;i<n-1;i++){
		if (s[i-1]==s[i+1]){
			int cont=0, ans=0;
			for(j=0;j<n;j++){
				if(j!=0 && j!=n-1
					&& ( j<i-1 || j>i+1 )
					&& s[j-1]==s[j+1]) cont++;
				else{
					ans^=grundy[cont+1];
					cont=1;
				}
			}
			if(ans==0) {
				cout<<"First"<<endl;
				cout<<i+1<<endl;
				return 0;
			}
		}
	}
	cout<<"Second"<<endl;
	return 0;
}