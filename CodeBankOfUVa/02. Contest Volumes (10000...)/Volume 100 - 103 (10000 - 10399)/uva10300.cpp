/****
	*@Polo-shen
	*
	*/
#include <iostream>
using namespace std;
typedef long long int64;
int main(){
    int n;
    cin>>n;
    while (n--){
	int f;int64 s,a,e,ans=0;
	cin>>f;
	while (f--){
		cin>>s>>a>>e;
		ans+=s*e;
	}
	cout<<ans<<endl;
    }
    return 0;
}
