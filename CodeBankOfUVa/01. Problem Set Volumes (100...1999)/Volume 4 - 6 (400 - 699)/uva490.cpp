/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    string a[110],s;int len[110],i=0,maxl=0;
    while (getline(cin,s)){
		a[i]=s;len[i]=(a[i]).size();
		maxl=(len[i]>maxl)?len[i]:maxl;
		i++;
    }
    for (int k=0;k<maxl;k++){
		for (int j=i-1;j>=0;j--)
			cout<<((k<len[j])?(a[j][k]):' ');
		cout<<endl;
    }
    return 0;
}
