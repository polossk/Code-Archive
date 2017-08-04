/****
	*@Polo-shen
	*
	*/
#include <iostream>
#include <cmath>
using namespace std;
typedef long long int64;
int main(){
	int64 a,b;
	while (cin>>a>>b){
		int64 c;
		c=a-b;
		c=(c>0)?c:-c;
		cout<<c<<endl;
	}
    return 0;
}
