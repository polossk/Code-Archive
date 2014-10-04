/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <string>
using namespace std;
typedef long long int64;
int main(){
	string str1;
	while(getline(cin,str1) && !str1.empty()){
		string str2(str1);
		string::size_type i;
		for(i=0;i!=str1.size();i++){
			str2[i]-=7;
		}
		cout<<str2<<endl;
	}
	return 0;
}
